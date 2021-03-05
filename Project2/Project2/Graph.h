#pragma once
#include <list>

#include "Vertex.h"

class Graph
{
public:
	//List of vertices in graph
	list<Vertex> verticies;
	int** adjMatrix;
	Vertex currentVertex;

	// Adds vertex into list of vertices
	void AddVertex(Vertex vert);

	//
};
