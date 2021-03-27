#include "pch.h"
#include "MyGraph.h"


MyGraph::MyGraph(int sX, int sY, int eX, int eY, int w, int h)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
	width = w;
	height = h;
	
	//Sets up adjMatrix
	adjMatrix = new int* [width*height];
	for (int i = 0; i < width*height; i++)
	{
		adjMatrix[i] = new int[height*width];
	}
	for(int i=0;i<width*height;i++)
	{
		for(int j=0;j<width*height;j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
}

// On moving into new vertex push it to stack. Mark it as visited.
// UNFINISHED?
void MyGraph::AddVertex(Vertex* vert)
{
	vertStack.push(vert);
	verticies.push_back(vert);
	//vert->visited = true;
}

// Assigns heurstic value to individual vertexes
// FINISHED
void MyGraph::AssignHeuristic(Vertex* vert)
{
	vert->heuristic = (endX - vert->xPos) + (endY - vert->yPos);
}

// If no adj unvisited vertex, pop it from stack
// Else push adjacent vertex into stack
//UNFINISHED
void MyGraph::RemoveVertex()
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
void MyGraph::FillAdjMatrix()
{


	
	for(int i=0;i<verticies.size();i++) // verticies is a vector rather than an arr
										// so each "vertical" adjacency is width positions away
	{
		for (int j = 0; j < verticies.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			if (i - width > 0) // Any adj vertex above
			{
				adjMatrix[i][j] = AddEdge(verticies.at(i), verticies.at(i - width));
				
			}
			if (i + width < height * width) // Any adj vertex below
			{
				adjMatrix[i][j] = AddEdge(verticies.at(i), verticies.at(i +width));
			}
			if (i - 1 > 0) // Any left adj vertex
			{
				adjMatrix[i][j] = AddEdge(verticies.at(i), verticies.at(i - 1));
			}
			if (i + 1 < height * width) // Any right adj vertex
			{
				adjMatrix[i][j] = AddEdge(verticies.at(i), verticies.at(i +1));
			}
			
		}

		

	}
}

// Adds edges between the two vertexes if they are adjacent and not walls.
int MyGraph::AddEdge(Vertex* vert1, Vertex* vert2)
{
	if(vert1->isWall || vert2->isWall)
	{
		return 0; // if either are a wall, return no edges
	}
	return 1; // Returns weight of 1 for adj matrix
	
}

MyGraph::~MyGraph()
{
	for(int i=0;i<verticies.size();i++)
	{
		delete verticies.at(i);
		
	}
	for(int i=0;i<width;i++)
	{
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;
	verticies.clear();
	cout << "Graph class yeet" << endl;
}
