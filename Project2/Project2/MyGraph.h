#pragma once
#include <list>
#include <stack>
#include <vector>
#include "Vertex.h"


using namespace std;
 class __declspec(dllexport) MyGraph
{
public:
	//List of vertices in graph
	vector<Vertex*> vertices; //
	int** adjMatrix; //   2D Array of adjacencies
	
	Vertex* currentVertex; // Try to use ptrs as much as possible
	stack<Vertex*> vertStack; // Stack of verts (Last In First Out)
	Vertex* startVertex;
	Vertex* endVertex;
	
	// Take these in from Source.cpp, save it here to reduce amnt of times needed to call in this info.
	int startX;
	int startY;
	int endX;
	int endY;
	int width;
	int height;
	int vertexCount;
	
	//Constructors
	MyGraph(int sX, int sY, int eX, int eY, int w, int h);


	//MyGraph();

	//Destructors
	~MyGraph();

	//Methods
	
	// Adds vertex into list of vertices
	void AddVertex(Vertex* vert);

	// If no adjacent unvisited, pop vertex.
	void RemoveVertex();
	
	// Assigns the Heuristic value to the vertex
	// Using Manhattan Values
	void AssignHeuristic(Vertex* vert);

	void FillAdjMatrix(); // Fills the adjacency matrix

	static int AddEdge(Vertex* vert1, Vertex* vert2); // Adds an edge between the two


	//int GetNodeIndex(int x, int y); // ???? Unsure 

	Vertex* FindVertex(int idx);
	Vertex* FindVertex(int x, int y);
	void SolveMaze();


	void AStarTest();

	void SetStart(int x, int y);
	void SetEnd(int x, int y);
	
	void printNodes();
	void printMatrix();
	vector<Vertex*> buildPath();
};
