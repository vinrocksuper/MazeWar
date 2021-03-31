#include "pch.h"
#include "MyGraph.h"
#include <queue>


MyGraph::MyGraph(int sX, int sY, int eX, int eY, int w, int h)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
	width = w;
	height = h;
	maze = nullptr;	
	currentVertex = nullptr;

	
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
	
	if(maze != nullptr)
	{
		// add nodes to graph

		for (size_t i = 0; i < width; i++)
		{
			for (size_t j = 0; j < height; j++)
			{
				if (maze[i][j] != 1)
				{
					Vertex* node = new Vertex(); // Possible memory leak? (if new -> then delete is necessary)
					node->xPos = i;
					node->yPos = j;
					node->heuristic = abs((int)(endX - i)) + abs((int)(endY - j));
					node->visited = false;
					if (maze[i][j] == 0)
						node->weight = 1;
					else
						node->weight = maze[i][j];
					node->lowestCost = INT_MAX;
					vertices.push_back(node); // Vertices should only have non-walls
				}
			}
		}
		
	}
	

	
}

// On moving into new vertex push it to stack. Mark it as visited.
// UNFINISHED?
void MyGraph::AddVertex(Vertex* vert)
{
	vertStack.push(vert);
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
// FINISHED?
void MyGraph::RemoveVertex()
{
	bool zeroAdj = true; // Assume no adjacencies left.
	for(int i=0;i < height;i++)
	{
		if(adjMatrix[currentVertex->xPos][i] == 1) // if adjacent
		{
			Vertex* adjVert = FindVertex(currentVertex->xPos, i);
			if(!adjVert->visited) // if adj and not visited
			{
				adjVert->previousVertex = currentVertex;
				adjVert->visited = true;
				// push adj vertex into stack
				AddVertex(adjVert);
				zeroAdj = false;
			}
		}
	}
	if(zeroAdj) // Since no adjacent vertex, pop it from stack.
	{
		vertStack.pop();
	}
}



Vertex* MyGraph::FindVertex(int x, int y)
{
	for (Vertex* vertex : vertices)
	{
		if(vertex->isWall)
		{
			continue;
		}
		if (vertex->xPos == x && vertex->yPos == y)
		{
			return vertex; // Returns vertex ptr
		}
	}
	return nullptr; // Returns nullptr if not found
}


//Fills the Adjacency Matrix
void MyGraph::FillAdjMatrix()
{	
	for(int i=0;i<vertices.size();i++) // verticies is a vector rather than an arr
										// so each "vertical" adjacency is width positions away
	{
		for (int j = 0; j < vertices.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			if (i - width > 0) // Any adj vertex above
			{
				adjMatrix[i][j] = AddEdge(vertices.at(i), vertices.at(i - width));
				
			}
			if (i + width < height * width) // Any adj vertex below
			{
				adjMatrix[i][j] = AddEdge(vertices.at(i), vertices.at(i +width));
			}
			if (i - 1 > 0) // Any left adj vertex
			{
				adjMatrix[i][j] = AddEdge(vertices.at(i), vertices.at(i - 1));
			}
			if (i + 1 < height * width) // Any right adj vertex
			{
				adjMatrix[i][j] = AddEdge(vertices.at(i), vertices.at(i +1));
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
	for(int i=0;i<vertices.size();i++)
	{
		delete vertices.at(i);
		
	}
	for(int i=0;i<width;i++)
	{
		delete[] adjMatrix[i];
	}
	delete[] adjMatrix;
	vertices.clear();
	cout << "Graph class yeet" << endl;
}


void MyGraph::SolveMaze(Vertex* startVertex, Vertex* endVertex)
{
	Vertex* current = startVertex;
	priority_queue <Vertex*> openList;
	openList.push(startVertex);
	vector<Vertex*> closedList;
	
	// While lowest distance vertex in openList is not the goal
	while (openList.top() != endVertex) {
		current = openList.top();
		openList.pop();
		closedList.push_back(current);

		// For each neighbor of current
		vector<Vertex*> neighborsList; 
		
		for (int i = 0; i < sizeof(adjMatrix); i++) {
			
		}
	}

}


