#include "pch.h"
#include "Vertex.h"


Vertex::Vertex(int x, int y)
{
	xPos = x;
	yPos = y;
	visited = false;
	previousVertex = nullptr;
}

Vertex::Vertex()
{
}

Vertex::~Vertex()
{
	if(previousVertex != nullptr)
	{
		previousVertex = nullptr;
	}
}
