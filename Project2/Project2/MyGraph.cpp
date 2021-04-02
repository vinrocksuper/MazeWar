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
	/**
	 * 
	 *
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
					node->index = vertexCount;
					node->open = true;
					vertexCount++;
					vertices.push_back(node); // Vertices should only have non-walls
					
				}
			}
		}
		
	}
	*/

	
}

// On moving into new vertex push it to stack. Mark it as visited.
// UNFINISHED?
void MyGraph::AddVertex(Vertex* vert)
{
	AssignHeuristic(vert);
	vert->visited = false;
	vert->index = vertexCount;
	vert->open = true;
	vertStack.push(vert);
	vertices.push_back(vert);
	
	vertexCount++;
}

// Assigns heuristic value to individual vertexes
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
		if(adjMatrix[currentVertex->index][i] == 1) // if adjacent
		{
			Vertex* adjVert = FindVertex(i);
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
	for(int i=0;i<vertices.size();i++) // verticies is a vector rather than an arr
										// so each "vertical" adjacency is width positions away
	{
		for (int j = 0; j < vertices.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			if (i - width >= 0) // Any adj vertex above
			{
				adjMatrix[i][i-width] = AddEdge(vertices.at(i), vertices.at(i - width));
				
			}
			if (i + width < height * width) // Any adj vertex below
			{
				adjMatrix[i][i + width] = AddEdge(vertices.at(i), vertices.at(i +width));
			}
			if (i - 1 >= 0) // Any left adj vertex
			{
				adjMatrix[i][i - 1] = AddEdge(vertices.at(i), vertices.at(i - 1));
			}
			if (i + 1 < height * width) // Any right adj vertex
			{
				adjMatrix[i][i + 1] = AddEdge(vertices.at(i), vertices.at(i +1));
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


void MyGraph::SolveMaze()
{
	currentVertex = startVertex;
	priority_queue <Vertex*, vector<Vertex*>, greater<Vertex*>> openList; // MIN-HEAP
	priority_queue <Vertex*, vector<Vertex*>, greater<Vertex*>> openListCopy; // MIN-HEAP
	openList.push(startVertex);
	vector<Vertex*> closedList;

	bool inOpen = true;
	bool inClosed = true;

	openListCopy = openList;

	// While lowest distance vertex in openList is not the goal
	while (openList.top() != endVertex) {
		currentVertex = openList.top();
		openList.pop();
		closedList.push_back(currentVertex);

		// For each neighbor of current
		vector<Vertex*> neighborsList;
		for (int i = 0; i < sizeof(adjMatrix); i++) {
			if (adjMatrix[currentVertex->index][i] == 1)
			{
				neighborsList.push_back(FindVertex(i));
			}
		}

		for (Vertex* neighbor : neighborsList) {
			int Cost = (currentVertex->lowestCost - startVertex->lowestCost) + (neighbor->lowestCost - currentVertex->lowestCost);
			int GNeighbor = neighbor->lowestCost - startVertex->lowestCost;
			
			// If neighbor in Open and Cost < G(Neighbor)
			for (int i = 0; i < openList.size(); i++) {
				if (neighbor == openListCopy.top() && Cost < GNeighbor) {
					delete closedList[i];
				}
				inOpen = false;
				openListCopy.pop();
			}
			
			// If neighbor in closed and Cost < G(Neighbor)
			for (int i = 0; i < sizeof(closedList); i++) {
				if (neighbor == closedList[i] && Cost < GNeighbor) {
					delete closedList[i];
				}
				inClosed = false;
			}

			// If neighbor not in OpenList and Not in Closed list
			if (inOpen == false && inClosed == false) {
				GNeighbor = Cost;
				openList.push(neighbor);
				neighbor->previousVertex = currentVertex;

			}
		}
	}
}

// Vincent Li's A-Star attempt. Feel free to comment out.
// Possibly finished? Steve said looks MOSTLY right. Will need to figure out what that means?
void MyGraph::AStarTest()
{
	startVertex = FindVertex(startX, startY);
	endVertex = FindVertex(endX, endY);
	vector<Vertex*> openList; 
	openList.push_back(startVertex); // q
	vector<Vertex*> closedList;

	while(openList.back() != endVertex)
	{
		currentVertex = openList.back();
		closedList.push_back(currentVertex);
		currentVertex->visited = true;

		// For each neighbor of current
		vector<Vertex*> neighborsList;

		for (int i = 0; i < vertexCount; i++) {
			if (adjMatrix[currentVertex->index][i] == 1)
			{
				Vertex* possibleNeighbor = FindVertex(i);
				if(possibleNeighbor->visited == false)
				{
					neighborsList.push_back(possibleNeighbor);
					possibleNeighbor->visited = true;
				}
				
			}
		}

		for(int i=0;i<sizeof(neighborsList);i++)
		{
			Vertex* neighbor = neighborsList[i];
			int cost = currentVertex->heuristic + 1; // Cost = G(Current) + weight
			bool inOpen = true;
			bool inClosed = true;
			for(int i=0;i<openList.size();i++)
			{
				if(openList[i] == neighbor && neighbor->heuristic <  cost)
				{
					openList.erase(openList.begin()+i); // removes from openList @pos i
					inOpen = false;
				}
			}
			for(int i=0;i<closedList.size();i++)
			{
				if(closedList[i] == neighbor && closedList[i]->heuristic < cost)
				{
					closedList.erase(closedList.begin() + i); // removes from closedList @pos i
					inClosed = false;
				}
			}
			if(!inOpen && !inClosed) 
			{
				neighbor->lowestCost = cost;
				neighbor->previousVertex = currentVertex;
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

void MyGraph::printNodes()
{
	for (auto && vertex : vertices)
	{
		cout << vertex->xPos << ", " << vertex->yPos << ", heuristic " << vertex->heuristic << endl;
	}
}
