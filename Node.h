#pragma once
#include<iostream>
#include"Edge.h"
using namespace std;
class Node {
public:
	Node* next;
	Edge* adj;
	char name;
	bool seen;
public:

	Node() {
		next =  NULL;
		adj = NULL;
		name = NULL;
		seen = false;
	}

	Node(char name) {
		this->name = name;
		adj = NULL;
		next = NULL;
		seen = false;
	}

	Node(char name, Node* next) {
		this->name = name;
		adj = NULL;
		this->next = next;
		seen = false;
	}

	Node(char name, Node* next, Edge* adj) {
		this->name = name;
		this->adj = adj;
		this->next = next;
		seen = false;
	}

	void IsSeen() {
		seen = true;
	}
};