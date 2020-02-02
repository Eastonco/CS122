#include "Node.h"


Node::Node(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
}

void Node::setmData(string newData)
{
	mData = newData;
}

void Node::setmpLeft(Node * newLeft)
{
	mpLeft = newLeft;
}

void Node::setmpRight(Node * newRight)
{
	mpRight = newRight;
}

string Node::getmData()
{
	return mData;
}

Node *& Node::getmpLeft()
{
	return mpLeft;
}

Node *& Node::getmpRight()
{
	return mpRight;
}

void Node::printData()
{
	cout << mData;
}
