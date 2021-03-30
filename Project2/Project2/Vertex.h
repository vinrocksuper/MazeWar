#pragma once

class __declspec(dllexport)  Vertex
{
public:
	//Fields
	int xPos; // X pos on graph
	int yPos; // Y pos on graph
	int heuristic; // Estimate on cost
	bool visited; // has the vert been visited yet true:if
	Vertex* previousVertex; // ptr to previous vert
	bool isWall; // is the Vertex a wall, false if not a wall, true if
	int open; // for the mazeData itself, 0 if open, 1 if wall

	
	int weight; // UNSURE IF NECESSARY
	int lowestCost; // UNSURE IF NECESSARY

	
	//Constructor
	Vertex(int x, int y);
	Vertex();
	~Vertex();
	//Methods

	
};
