#include "Graph.h"
Graph::Graph() {
	start = NULL;
	size = 0;
}

Graph::~Graph() {

}

void Graph::DeleteGraph(Node* p) {

}

void Graph::InsertNode(char p) {
	start = new Node(p, start);
	size++;
}

Node* Graph::FindNode(char p) {
	Node* tmp = start;
	while (tmp != NULL && tmp->name != p) {
		tmp = tmp->next;
	}
	return tmp;
}

void Graph::InsertEdge(char a, char b, int weight) {
	Node* Pa = FindNode(a);
	Node* Pb = FindNode(b);

	if (Pa != NULL && Pb != NULL) {
		Edge* ed = new Edge(Pb, Pa->adj, weight);
		Pa->adj = ed;
	}
	else cout << "Los unos cvorova !!" << endl;
}

Edge* Graph::FindEdge(char a, char b) {
	Node* Pa = FindNode(a);
	Node* Pb = FindNode(b);

	if (Pa != NULL && Pb != NULL) {
		Edge* ed = Pa->adj;
		while (ed != NULL && ed->dest != Pb)
			ed = ed->link;

		return ed;
	}
	else return 0;
}

bool Graph::EdgeExists(char a, char b) {
	if (FindEdge(a, b))
		return true;
	return false;
}

void Graph::CheapPath(char a, char b) {
	Node* Pa = FindNode(a);
	Node* Pb = FindNode(b);
	Node* tmp = start;
	Pa->IsSeen();
	char* path = new char[size];
	int i = 0;
	char n = 0;
	int min = 100;
	int edgeWeight = 0;
	int sum = 0;
	path[i] = Pa->name;

	while (Pa->name != Pb->name) {
		if (i == size)
			break;

		while (tmp != NULL) {

			if (EdgeExists(Pa->name, tmp->name) && tmp->seen == false) {
				Edge* ed = FindEdge(Pa->name, tmp->name);
				if (min > ed->weight) {
					min = ed->weight;
					n = tmp->name;
					edgeWeight = ed->weight;
				}
			}
			tmp = tmp->next;
		}
		min = 100;
		path[i++] = n;
		Pa = FindNode(n);
		Pa->IsSeen();
		sum += edgeWeight;
		tmp = start;
	}
	
	cout << "Putanja od cvora [" << a << "] do cvora [" << b << "]: " << endl;
	for (int j = 0; j < i; j++) {
		cout << "[" << path[j] << "] ";
	}
	cout << endl;
	cout << "Tezina puta: " << sum << endl;
}

void Graph::ExpencivePath(char a, char b) {

}

bool Graph::DeleteNode(char p) {
	Node* ptr;
	if (start == NULL)
		return false;
	if (start->name == p) {
		Edge* pot = start->adj;
		while (pot != NULL) {
			Edge* tpot = pot->link;
			delete pot;
			pot = tpot;
		}
	}
}

bool Graph::DeleteEdge(char a, char b) {
	Edge* pot = FindEdge(a, b);
	if (pot == NULL)
		return false;

		Node* pa = FindNode(a);
		if (pot == pa->adj) {
			pa->adj = pot->link;
			delete pot;
			return true;
		}

		Edge* tpot = pa->adj;
		while (tpot->link != pot)
			tpot = tpot->link;
		tpot->link = pot->link;
		delete pot;
		return true;
}

void Graph::PrintGraph() {
	Node* tmp1 = start;
	Node* tmp2 = start;

	while (tmp1 != NULL) {
		cout << "["<<tmp1->name << "] ";
		while (tmp2 != NULL) {
			if (EdgeExists(tmp1->name, tmp2->name) && EdgeExists(tmp2->name, tmp1->name)) {
				Edge* ed = FindEdge(tmp1->name, tmp2->name);
				cout << "[" << tmp1->name << "] <(" << ed->weight << ")> " << "[" << tmp2->name << "] ";
			}
			else if (EdgeExists(tmp1->name, tmp2->name) && !EdgeExists(tmp2->name, tmp1->name)) {
				Edge* ed = FindEdge(tmp1->name, tmp2->name);
				cout << "[" << tmp1->name << "] -(" << ed->weight << ")> " << "[" << tmp2->name << "] ";
			}
			else
				cout << "[" << tmp2->name << "] ";

			tmp2 = tmp2->next;
		}
		tmp2 = start;
		tmp1 = tmp1->next;
		cout << endl;
		cout << endl;
	}
}

Node* Graph::FindNode(char p) {
	Node* tmp = start;
	while (tmp != NULL && tmp->name != p) {
		Edge* ed = tmp->adj;
		while (ed != NULL) {
			Edge* edr = ed->dest->adj;
			while (edr != NULL && edr->dest != tmp) {
				edr = edr->link;
			}
			if (edr == nullptr)
			{
				ed->dest->adj = new Edge(tmp, ed->dest->adj);
			}
			ed = ed->link;
		}
		tmp = tmp->next;
	}
	return tmp;
}

