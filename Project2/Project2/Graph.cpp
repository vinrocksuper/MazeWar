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
	
	//Sets up adjMatrix
	adjMatrix = new int* [width];
	for (int i = 0; i < width; i++)
	{
		adjMatrix[i] = new int[height];
	}

}

// On moving into new vertex push it to stack. Mark it as visited.
// UNFINISHED?
void Graph::AddVertex(Vertex* vert)
{
	vertStack.push(vert);
	//vert->visited = true;
}

// Assigns heurstic value to individual vertexes
// FINISHED
void Graph::AssignHeuristic(Vertex* vert)
{
	vert->heuristic = (endX - vert->xPos) + (endY - vert->yPos);
}

// If no adj unvisited vertex, pop it from stack
// Else push adjacent vertex into stack
//UNFINISHED
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


//Fills the Adjacency Matrix
void Graph::FillAdjMatrix() 
{
	for(int i=0;i<verticies.size();i++) // verticies is a vector rather than an arr
										// so each "vertical" adjacency is width positions away
	{
		if(i-width > 0) // Any adj vertex above
		{
			adjMatrix[i/width][i%width] = AddEdge(verticies.at(i), verticies.at(i - width));
		}
		if(i+width < height*width) // Any adj vertex below
		{
			adjMatrix[i / width][i % width] = AddEdge(verticies.at(i), verticies.at(i +width));
		}
		if(i-1 > 0) // Any left adj vertex
		{
			adjMatrix[i / width][i % width] = AddEdge(verticies.at(i), verticies.at(i - 1));
		}
		if(i+1 < height*width) // Any right adj vertex
		{
			adjMatrix[i / width][i % width] = AddEdge(verticies.at(i), verticies.at(i +1));
		}
	}
}

// Adds edges between the two vertexes if they are adjacent and not walls.
int Graph::AddEdge(Vertex* vert1, Vertex* vert2)
{
	if(vert1->isWall || vert2->isWall)
	{
		return 0; // if either are a wall, return no edges
	}
	return 1; // Returns weight of 1 for adj matrix
	
}

Graph::~Graph()
{
}
