#include "Level3.h"



//Path for A Star Representation
std::vector<Node*> path3;

//First level Rows Cols making of the grid
static int const ROWS3 = 1000;
static int const COLS3 = 1000;
static int arr[ROWS3][COLS3];
int amountNodes3 = ROWS3 * COLS3;
Graph<NodeData, int> levelGraph3(amountNodes3);

//Function to say what we are visiting
void LevelThree::visit(Node* t_node)
{
	std::cout << "Visiting: " << t_node->m_data.m_name << std::endl;
}

//Level One Graph Set up
LevelThree::LevelThree()
{
	//Set Array relative to graph
	int inputNumber = 0;
	for (int y = 0; y < COLS3; y++)
	{
		for (int x = 0; x < ROWS3; x++)
		{
			arr[x][y] = inputNumber;
			inputNumber++;
		}
	}

	NodeData nodeData;
	int nodeIndex = 0;
	std::ifstream myfile;

	//Create the Graph
	for (int y = 0; y < COLS3; y++)
	{
		for (int x = 0; x < ROWS3; x++)
		{
			nodeData.xPos = x * TILE_WIDTH;
			nodeData.yPos = y * TILE_WIDTH;


			if (y == 3 && x == 3)
			{
				nodeData.passable = false;
				nodeData.rectangle.setFillColor(sf::Color(255, 0, 0, 255));

			}
			else
			{
				nodeData.passable = true;
				nodeData.rectangle.setFillColor(sf::Color(255, 255, 255, 255));
			}

			levelGraph3.addNode(nodeData, arr[x][y]);
		}
	}

	//Create the arcs for sourounding nodes
	for (int y = 0; y < COLS3; y++)
	{
		for (int x = 0; x < ROWS3; x++)
		{
			// List all neighbors:
			for (int direction = 0; direction < 9; direction++) {
				if (direction == 4) continue; // Skip ourselves

				int n_row = x + ((direction % 3) - 1); // Neighbor row
				int n_col = y + ((direction / 3) - 1); // Neighbor column

				// Check the bounds:
				if (n_row >= 0 && n_row < ROWS3 && n_col >= 0 && n_col < COLS3)
				{

					if (levelGraph3.nodeIndex(arr[n_row][n_col])->m_data.passable == true)
					{

						//Distance between point and neighbour
						float weight = sqrt((levelGraph3.nodeIndex(arr[n_row][n_col])->m_data.xPos - levelGraph3.nodeIndex(arr[x][y])->m_data.xPos)
							* (levelGraph3.nodeIndex(arr[n_row][n_col])->m_data.xPos - levelGraph3.nodeIndex(arr[x][y])->m_data.xPos)
							+ (levelGraph3.nodeIndex(arr[n_row][n_col])->m_data.yPos - levelGraph3.nodeIndex(arr[x][y])->m_data.yPos)
							* (levelGraph3.nodeIndex(arr[n_row][n_col])->m_data.yPos - levelGraph3.nodeIndex(arr[x][y])->m_data.yPos));

						//std::cout << weight << std::endl;
						levelGraph3.addArc(arr[n_row][n_col], arr[x][y], weight);
					}
				}
			}
		}
	}
}

LevelThree::~LevelThree()
{
}

void LevelThree::update(sf::Time t_deltaTime)
{
	for (int i = 0; i < amountNodes3; i++)
	{
		levelGraph3.nodeIndex(i)->m_data.rectangle.setSize(sf::Vector2f(TILE_WIDTH, TILE_WIDTH));
		levelGraph3.nodeIndex(i)->m_data.rectangle.setOutlineThickness(1);
		levelGraph3.nodeIndex(i)->m_data.rectangle.setOutlineColor(sf::Color::Black);
		levelGraph3.nodeIndex(i)->m_data.rectangle.setPosition(levelGraph3.nodeIndex(i)->m_data.xPos, levelGraph3.nodeIndex(i)->m_data.yPos);
	}

	//Testing aStar by colouring in the square
	levelGraph3.aStar(levelGraph3.nodeIndex(arr[0][0]), levelGraph3.nodeIndex(arr[15][29]), path3);
	for (auto& node : path3) {

		node->m_data.rectangle.setFillColor(sf::Color(0, 255, 0, 255));
		node->m_data.rectangle.setOutlineColor(sf::Color::Black);
	}
}

void LevelThree::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < amountNodes3; i++)
	{
		t_window.draw(levelGraph3.nodeIndex(i)->m_data.rectangle);
	}

}

void LevelThree::setup(sf::Font& t_font)
{
	//Rows = ROWS3;
}

void LevelThree::initialise()
{
}
