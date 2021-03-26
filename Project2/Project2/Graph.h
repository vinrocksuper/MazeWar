#pragma once
#include <list>
#include <stack>
#include <vector>
#include "Vertex.h"


using namespace std;
class Graph
{
public:
	//List of vertices in graph
	vector<Vertex*> verticies; //
	int** adjMatrix; //   2D Array of adjacencies

	
	Vertex* currentVertex; // Try to use ptrs as much as possible
	stack<Vertex*> vertStack; // Stack of verts (Last In First Out)

	
	// Take these in from Source.cpp, save it here to reduce amnt of times needed to call in this info.
	int startX;
	int startY;
	int endX;
	int endY;
	int width;
	int height;
	//Constructors
	Graph(int sX, int sY, int eX, int eY, int w, int h);


	//Destructors
	~Graph();

	//Methods
	
	// Adds vertex into list of vertices
	void AddVertex(Vertex* vert);

	// If no adjacent unvisited, pop vertex.
	void RemoveVertex();
	
	// Assigns the Heuristic value to the vertex
	// Using Manhattan Values
	void AssignHeuristic(Vertex* vert);

	void FillAdjMatrix();

	int AddEdge(Vertex* vert1, Vertex* vert2);
};
