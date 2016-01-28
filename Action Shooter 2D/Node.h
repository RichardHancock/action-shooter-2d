#pragma once
#include <vector>

class Node {
public:
	Node();
	~Node();


private:
	int xPos;
	int yPos;

	std::vector<Node*> nodeChildren;
	Node *parent;
	int numChildren;
	

};