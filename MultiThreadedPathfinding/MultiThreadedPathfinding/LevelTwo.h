#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

#include <iostream>
#include <fstream>
#include "Graph.h"
#include "GraphArc.h"
#include "GraphNode.h"
#include "NodeData.h"
#include "Globals.h"

typedef GraphArc<NodeData, int> Arc;
typedef GraphNode<NodeData, int> Node;

class LevelTwo
{
public:
	LevelTwo();
	~LevelTwo();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();
	void visit(Node* t_node);

	Graph<NodeData, int> levelGraph2;
private:



};