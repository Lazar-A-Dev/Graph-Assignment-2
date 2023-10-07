#pragma once
#include<iostream>
using namespace std;
class Node;
class Edge {
public:
	Node* dest;
	Edge* link;
	int weight;

public:
	Edge() {
		dest = NULL;
		link = NULL;
		weight = 0;
	}

	Edge(Node* dest, Edge* link) {
		this->dest = dest;
		this->link = link;
		weight = 0;
	}

	Edge(Node* dest, Edge* link, int weight) {
		this->dest = dest;
		this->link = link;
		this->weight = weight;
	}

};
