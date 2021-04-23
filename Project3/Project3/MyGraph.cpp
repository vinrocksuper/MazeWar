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
	currentVertex = nullptr;
	vertexCount = 0;
}

//Sets the dimensions for the graph.
void MyGraph::SetDimensions(int w, int h)
{
	width = w;
	height = h;
}

//Sets up adjMatrix and calls FillMatrix()
void MyGraph::setupMatrix()
{

	adjMatrix = new int* [width * height];
	for (int i = 0; i < width * height; i++)
	{
		adjMatrix[i] = new int[height * width];
	}
	for (int i = 0; i < width * height; i++)
	{
		for (int j = 0; j < width * height; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
	FillAdjMatrix();
}

// Assigns default values to vertexes. Increments vertex count and adds to the vertex list.
void MyGraph::AddVertex(Vertex* vert)
{
	vert->visited = false;
	vert->index = vertexCount;
	vert->open = true;
	vert->total = INT_MAX;
	vertices.push_back(vert);
	
	vertexCount++;
}

// Assigns heuristic value to individual vertexes
// FINISHED
void MyGraph::AssignHeuristic(Vertex* vert)
{


		vert->heuristic = abs(endX - vert->xPos) + abs(endY - vert->yPos);

	
}


//Finds vertex either using coordinate or index
Vertex* MyGraph::FindVertex(int idx)
{
	for (Vertex* vertex : vertices)
	{
		if(vertex->isWall)
		{
			continue;
		}
		if (vertex->index == idx)
		{
			return vertex; // Returns vertex ptr
		}
	}
	return nullptr; // Returns nullptr if not found
}
Vertex* MyGraph::FindVertex(int x, int y)
{
	for(Vertex* vertex: vertices)
	{
		if(vertex->isWall)
		{
			continue;
		}
		if(vertex->xPos == x && vertex->yPos == y)
		{
			return vertex;
		}
	}
	return nullptr;
}


//Fills the Adjacency Matrix
void MyGraph::FillAdjMatrix()
{	
	for(int i=0;i<vertices.size();i++) // vertices is a vector rather than an arr
										// so each "vertical" adjacency is width positions away
	{
		for (int j = 0; j < vertices.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			if(vertices[i]->xPos == vertices[j]->xPos && abs(vertices[i]->yPos-vertices[j]->yPos) == 1)
			{
				adjMatrix[i][j] = AddEdge(vertices.at(i), vertices.at(j));
			}
			if (vertices[i]->yPos == vertices[j]->yPos && abs(vertices[i]->xPos - vertices[j]->xPos) == 1)
			{
				adjMatrix[i][j] = AddEdge(vertices.at(i), vertices.at(j));
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

//Destructor
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

// A-star
// FINISHED.
void MyGraph::AStar()
{
	startVertex = FindVertex(startX, startY);
	endVertex = FindVertex(endX, endY);
	startVertex->total = 0;
	vector<Vertex*> openList; 
	openList.push_back(startVertex); // q
	vector<Vertex*> closedList;

	while(!openList.empty())
	{
		int lowest = INT_MAX;
		int index= -1;
		//Find index w/ least f value (heuristic + lowestCost)
		for(int i=0;i<openList.size();i++)
		{
			if (openList[i]->total <=lowest)
			{
				lowest = openList[i]->total;
				index = i;
				currentVertex = openList[i];
			}
		}

		
		openList.erase(openList.begin() + index); // Remove it from openlist
														// double check index >= 0
		closedList.push_back(currentVertex);
		currentVertex->visited = true;
		if(currentVertex == endVertex)
		{
			return;
		}
		// For each neighbor of current
		vector<Vertex*> neighborsList;

		for (int i = 0; i < vertexCount; i++) {
			if (adjMatrix[currentVertex->index][i] == 1)
			{
				Vertex* possibleNeighbor = FindVertex(i);
				if(!possibleNeighbor->visited)
				{
					possibleNeighbor->previousVertex = currentVertex;
					if (std::count(closedList.begin(), closedList.end(), possibleNeighbor))
					{
						continue;
					}
					possibleNeighbor->lowestCost = currentVertex->lowestCost + possibleNeighbor->weight;
					possibleNeighbor->total = possibleNeighbor->lowestCost + possibleNeighbor->heuristic;

					if (std::count(openList.begin(), openList.end(), possibleNeighbor))
					{
						if (possibleNeighbor->lowestCost > currentVertex->lowestCost)
						{
							continue;
						}
					}
					openList.push_back(possibleNeighbor);
				}

			}
		}
	}
}

//Backtracks from endVertex until startVertex.
//Pushes each Vertex into a vector, then returns that vector with startVertex on top, endVertex on bottom.
vector<Vertex*> MyGraph::buildPath()
{
	vector<Vertex*> vertexes;
	if(endVertex->previousVertex != nullptr)
	{
		Vertex* temp = endVertex;
		while(temp != nullptr) // StartVertex should have a nullptr for previousVertex
		{
			vertexes.push_back(temp);
			temp = temp->previousVertex;
		}
	}
	return vertexes;
}


//Prints Adjacency matrix. TESTING ONLY
void MyGraph::printMatrix()
{
	for(int i=0;i<vertexCount;i++)
	{
	
		for(int j=0;j<vertexCount;j++)
		{
			cout << adjMatrix[i][j];
		}
		cout << endl;
	}
}
//Prints all nodes w/ (X,Y) Heuristic and Index
void MyGraph::printNodes()
{
	for (auto && vertex : vertices)
	{
		if(vertex->lowestCost > 0)
		cout << vertex->xPos << ", " << vertex->yPos << ", heuristic " << vertex->heuristic << " index: " << vertex->index << "weight: " << vertex->weight << " LC: " << vertex->lowestCost << endl;

		
	}
}

//Sets (X,Y) for start/end
void MyGraph::SetStart(int x, int y)
{
	startX = x;
	startY = y;
}
void MyGraph::SetEnd(int x, int y)
{
	endX = x;
	endY = y;
}
