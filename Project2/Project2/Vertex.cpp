#include "pch.h"
#include "Vertex.h"


Vertex::Vertex(int x, int y)
{
	xPos = x;
	yPos = y;
	visited = false;
	
}

Vertex::~Vertex()
{
	if(previousVertex != nullptr)
	{
		delete previousVertex;
	}
}
