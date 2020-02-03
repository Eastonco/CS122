#include "Node.h"


Node::Node(Data const &newData)
{
	Data *d1 = new Data(newData);
	this->pData = d1; // overload
	this->pNext = nullptr;
}

void Node::setServiceTimee(int i) {
	this->pData->setServiceTime(i);
}



Node::~Node()
{
}

int Node::getTotalTime() const
{
	return this->pData->getTotalTime();
}

Node *Node::getNextPtr() const
{
	return this->pNext;
}

void Node::setNextPtr(Node * newNextPtr)
{
	this->pNext = newNextPtr;
}

int Node::getServiceTime() const
{
	return pData->getServiceTime();
}