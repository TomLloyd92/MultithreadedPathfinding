#include "LevelTwo.h"



//Path for A Star Representation
std::vector<Node*> path2;

//First level Rows Cols making of the grid
static int const ROWS2 = 100;
static int const COLS2 = 100;
static int arr[ROWS2][COLS2];
int amountNodes2 = ROWS2 * COLS2;

//Function to say what we are visiting
void LevelTwo::visit(Node* t_node)
{
	std::cout << "Visiting: " << t_node->m_data.m_name << std::endl;
}

//Level One Graph Set up
LevelTwo::LevelTwo()
{
	Graph<NodeData, int> theGraph(amountNodes2);

	levelGraph2 = theGraph;

	//Set Array relative to graph
	int inputNumber = 0;
	for (int y = 0; y < COLS2; y++)
	{
		for (int x = 0; x < ROWS2; x++)
		{
			arr[x][y] = inputNumber;
			inputNumber++;
		}
	}

	NodeData nodeData;
	int nodeIndex = 0;
	std::ifstream myfile;

	//Create the Graph
	for (int y = 0; y < COLS2; y++)
	{
		for (int x = 0; x < ROWS2; x++)
		{
			nodeData.xPos = x * TILE_WIDTH;
			nodeData.yPos = y * TILE_WIDTH;

			
			//Wall 1
			if (x == 3 && y >= 0 && y < 15)
			{
				nodeData.passable = false;
				nodeData.rectangle.setFillColor(sf::Color(0, 0, 0, 255));
			}
			//Wall 2
			else if (x == 15 && y > 15)
			{
				nodeData.passable = false;
				nodeData.rectangle.setFillColor(sf::Color(0, 0, 0, 255));
			}
			//Wall 3
			else if (x == 50 && y > 50)
			{
				nodeData.passable = false;
				nodeData.rectangle.setFillColor(sf::Color(0, 0, 0, 255));
			}
			//Wall 4
			else if (x == 20 && y < 20)
			{
				nodeData.passable = false;
				nodeData.rectangle.setFillColor(sf::Color(0, 0, 0, 255));
			}
			//Wall 5
			else if (x == 8 && y < 20 && y > 10)
			{
				nodeData.passable = false;
				nodeData.rectangle.setFillColor(sf::Color(0, 0, 0, 255));
			}
			//Wall 6
			else if (x == 25 && y < 28 && y > 16)
			{
				nodeData.passable = false;
				nodeData.rectangle.setFillColor(sf::Color(0, 0, 0, 255));
			}
			else
			{
				nodeData.passable = true;
				nodeData.rectangle.setFillColor(sf::Color(255, 255, 255, 255));
			}

			levelGraph2.addNode(nodeData, arr[x][y]);
		}
	}

	//Create the arcs for sourounding nodes
	for (int y = 0; y < COLS2; y++)
	{
		for (int x = 0; x < ROWS2; x++)
		{
			// List all neighbors:
			for (int direction = 0; direction < 9; direction++) {
				if (direction == 4) continue; // Skip ourselves

				int n_row = x + ((direction % 3) - 1); // Neighbor row
				int n_col = y + ((direction / 3) - 1); // Neighbor column

				// Check the bounds:
				if (n_row >= 0 && n_row < ROWS2 && n_col >= 0 && n_col < COLS2)
				{

					if (levelGraph2.nodeIndex(arr[n_row][n_col])->m_data.passable == true)
					{

						//Distance between point and neighbour
						float weight = sqrt((levelGraph2.nodeIndex(arr[n_row][n_col])->m_data.xPos - levelGraph2.nodeIndex(arr[x][y])->m_data.xPos)
							* (levelGraph2.nodeIndex(arr[n_row][n_col])->m_data.xPos - levelGraph2.nodeIndex(arr[x][y])->m_data.xPos)
							+ (levelGraph2.nodeIndex(arr[n_row][n_col])->m_data.yPos - levelGraph2.nodeIndex(arr[x][y])->m_data.yPos)
							* (levelGraph2.nodeIndex(arr[n_row][n_col])->m_data.yPos - levelGraph2.nodeIndex(arr[x][y])->m_data.yPos));

						//std::cout << weight << std::endl;
						levelGraph2.addArc(arr[n_row][n_col], arr[x][y], weight);
					}
				}
			}
		}
	}
}

LevelTwo::~LevelTwo()
{
}

void LevelTwo::update(sf::Time t_deltaTime)
{
	for (int i = 0; i < amountNodes2; i++)
	{
		levelGraph2.nodeIndex(i)->m_data.rectangle.setSize(sf::Vector2f(TILE_WIDTH, TILE_WIDTH));
		levelGraph2.nodeIndex(i)->m_data.rectangle.setOutlineThickness(1);
		levelGraph2.nodeIndex(i)->m_data.rectangle.setOutlineColor(sf::Color::Black);
		levelGraph2.nodeIndex(i)->m_data.rectangle.setPosition(levelGraph2.nodeIndex(i)->m_data.xPos, levelGraph2.nodeIndex(i)->m_data.yPos);
	}
}

void LevelTwo::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < amountNodes2; i++)
	{
		t_window.draw(levelGraph2.nodeIndex(i)->m_data.rectangle);
	}

}

void LevelTwo::setup(sf::Font& t_font)
{
	//Rows = ROWS2;
}

void LevelTwo::initialise()
{
}
