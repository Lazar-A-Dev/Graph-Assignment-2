#include<iostream>
#include"Graph.h"
using namespace std;
void main() {
	Graph g;
	g.InsertNode('U');
	g.InsertNode('V');
	g.InsertNode('W');
	g.InsertNode('X');
	g.InsertNode('L');
	g.InsertNode('F');
	g.InsertNode('D');
	g.InsertNode('G');
	g.InsertNode('H');
	g.InsertNode('P');
	g.InsertNode('Z');

	g.InsertEdge('U', 'W', 1);
	g.InsertEdge('W', 'U', 1);
	g.InsertEdge('U', 'V', 4);
	g.InsertEdge('V', 'U', 4);
	g.InsertEdge('W', 'V', 2);
	g.InsertEdge('V', 'W', 2);
	g.InsertEdge('W', 'X', 5);
	g.InsertEdge('X', 'W', 5);
	g.InsertEdge('W', 'Z', 10);
	g.InsertEdge('Z', 'W', 10);
	g.InsertEdge('X', 'V', 7);
	g.InsertEdge('V', 'X', 7);
	g.InsertEdge('V', 'L', 3);
	g.InsertEdge('L', 'V', 3);
	g.InsertEdge('L', 'D', 1);
	g.InsertEdge('D', 'L', 1);
	g.InsertEdge('X', 'D', 1);
	g.InsertEdge('D', 'X', 1);
	g.InsertEdge('X', 'G', 1);
	g.InsertEdge('G', 'X', 1);
	g.InsertEdge('D', 'P', 4);
	g.InsertEdge('P', 'D', 4);
	g.InsertEdge('G', 'H', 5);
	g.InsertEdge('H', 'G', 5);
	g.InsertEdge('G', 'P', 2);
	g.InsertEdge('P', 'G', 2);
	g.InsertEdge('H', 'Z', 6);
	g.InsertEdge('Z', 'H', 6);
	g.InsertEdge('P', 'Z', 2);
	g.InsertEdge('Z', 'P', 2);



	g.PrintGraph();
	cout << endl;
	g.CheapPath('L', 'H');
	system("pause");
}