#include "Level1.h"

//Path for A Star Representation
std::vector<Node*> path;

//First level Rows Cols making of the grid
static int const ROWS = 30;
static int const COLS = 30;
static int arr[ROWS][COLS];
int amountNodes = ROWS * COLS;
Graph<NodeData, int> levelGraph(amountNodes);

//Function to say what we are visiting
void LevelOne::visit(Node* t_node)
{
	std::cout << "Visiting: " << t_node->m_data.m_name << std::endl;
}

//Level One Graph Set up
LevelOne::LevelOne()
{
	//Set Array relative to graph
	int inputNumber = 0;
	for (int y = 0; y < COLS; y++)
	{
		for (int x = 0; x < ROWS; x++)
		{
			arr[x][y] = inputNumber;
			inputNumber++;
		}
	}

	NodeData nodeData;
	int nodeIndex = 0;
	std::ifstream myfile;

	//Create the Graph
	for (int y = 0; y < COLS; y++)
	{
		for (int x = 0; x < ROWS; x++)
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

			levelGraph.addNode(nodeData, arr[x][y]);
		}
	}

	//Create the arcs for sourounding nodes
	for (int y = 0; y < COLS; y++)
	{
		for (int x = 0; x < ROWS; x++)
		{
			// List all neighbors:
			for (int direction = 0; direction < 9; direction++) {
				if (direction == 4) continue; // Skip ourselves

				int n_row = x + ((direction % 3) - 1); // Neighbor row
				int n_col = y + ((direction / 3) - 1); // Neighbor column

				// Check the bounds:
				if (n_row >= 0 && n_row < ROWS && n_col >= 0 && n_col < COLS)
				{

					if (levelGraph.nodeIndex(arr[n_row][n_col])->m_data.passable == true)
					{

						//Distance between point and neighbour
						float weight = sqrt((levelGraph.nodeIndex(arr[n_row][n_col])->m_data.xPos - levelGraph.nodeIndex(arr[x][y])->m_data.xPos)
							* (levelGraph.nodeIndex(arr[n_row][n_col])->m_data.xPos - levelGraph.nodeIndex(arr[x][y])->m_data.xPos)
							+ (levelGraph.nodeIndex(arr[n_row][n_col])->m_data.yPos - levelGraph.nodeIndex(arr[x][y])->m_data.yPos)
							* (levelGraph.nodeIndex(arr[n_row][n_col])->m_data.yPos - levelGraph.nodeIndex(arr[x][y])->m_data.yPos));

						//std::cout << weight << std::endl;
						levelGraph.addArc(arr[n_row][n_col], arr[x][y], weight);
					}
				}
			}
		}
	}
}

LevelOne::~LevelOne()
{
}

void LevelOne::update(sf::Time t_deltaTime)
{
	for (int i = 0; i < amountNodes; i++)
	{
		levelGraph.nodeIndex(i)->m_data.rectangle.setSize(sf::Vector2f(TILE_WIDTH, TILE_WIDTH));
		levelGraph.nodeIndex(i)->m_data.rectangle.setOutlineThickness(1);
		levelGraph.nodeIndex(i)->m_data.rectangle.setOutlineColor(sf::Color::Black);
		levelGraph.nodeIndex(i)->m_data.rectangle.setPosition(levelGraph.nodeIndex(i)->m_data.xPos, levelGraph.nodeIndex(i)->m_data.yPos);
	}

	//Testing aStar by colouring in the square
	levelGraph.aStar(levelGraph.nodeIndex(arr[0][0]), levelGraph.nodeIndex(arr[15][29]), path);
	for (auto& node : path) {

		node->m_data.rectangle.setFillColor(sf::Color(0, 255, 0, 255));
		node->m_data.rectangle.setOutlineColor(sf::Color::Black);
	}
}

void LevelOne::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < amountNodes; i++)
	{
		t_window.draw(levelGraph.nodeIndex(i)->m_data.rectangle);
	}

}

void LevelOne::setup(sf::Font& t_font)
{
}

void LevelOne::initialise()
{
}
