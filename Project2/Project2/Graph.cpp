#include "pch.h"
#include "Graph.h"


Graph::Graph(int sX, int sY, int eX, int eY, int w, int h)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
	width = w;
	height = h;
	
	
}

// On moving into new vertex push it to stack. Mark it as visited.
void Graph::AddVertex(Vertex* vert)
{
	vertStack.push(vert);
	//vert->visited = true;
}

void Graph::AssignHeuristic(Vertex* vert)
{
	vert->heuristic = (endX - vert->xPos) + (endY - vert->yPos);
}

// If no adj unvisited vertex, pop it from stack
// Else push adjacent vertex into stack
void Graph::RemoveVertex()
{
	bool zeroAdj = true; // Assume no adjacencies left.
	for(int i=0;i < width;i++)
	{
		if(adjMatrix[currentVertex->xPos][i] == 1 )
		{
			// push adj vertex into stack
			zeroAdj = false; 
		}
	}
	if(zeroAdj) // Since no adjacent vertex, pop it from stack.
	{
		vertStack.pop();
	}
}
