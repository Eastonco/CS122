#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData = "", int numUnits = 0)
{
	mUnits = numUnits;
	this->setmData(newData);
}

TransactionNode::~TransactionNode()
{
}

void TransactionNode::printData()
{
	cout << "Units" << mUnits;
}

void TransactionNode::setUnits(int numUnits)
{
	mUnits = numUnits;
}

int TransactionNode::getUnits()
{
	return mUnits;
}
