#pragma once
#include"Edge.h"
#include"Node.h"
class Graph
{
public:
	Node* start;
	int size;

public:
	Graph();
	~Graph();
	void DeleteGraph(Node* p);
	void InsertNode(char p);
	Node* FindNode(char p);
	void InsertEdge(char a, char b, int weight);
	bool EdgeExists(char a, char b);
	Edge* FindEdge(char a, char b);
	void CheapPath(char a, char b);
	void ExpencivePath(char a, char b);
	bool DeleteNode(char p);
	bool DeleteEdge(char a, char b);
	void PrintGraph();
};

