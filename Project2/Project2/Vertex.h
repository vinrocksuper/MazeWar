﻿#pragma once

class Vertex
{
public:
	//Fields
	int xPos; // X pos on graph
	int yPos; // Y pos on graph
	int heuristic; // Estimate on cost
	int lowestCost;
	bool visited; // has the vert been visited yet true:if
	Vertex* previousVertex; // ptr to previous vert

	//Constructor
	Vertex(int x, int y);

	//Methods

	
};
