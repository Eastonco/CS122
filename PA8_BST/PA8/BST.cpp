#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

BST::~BST()
{
	destoryTree(mpRoot);
}

Node * BST::getRootPtr() const
{
	return mpRoot;
}

void BST::setRootPtr(Node * newNode)
{
	mpRoot = newNode;
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

void BST::insert(string newItem, int units)
{
	insert(newItem, units, mpRoot);
}

void BST::inOrderTraversal(Node * pRoot)
{
	if (pRoot != nullptr) {
		inOrderTraversal(pRoot->getmpLeft());
		cout << pRoot->getmData() << " ";
		inOrderTraversal(pRoot->getmpRight());
	}
	else {
		return;
	}
}

void BST::destoryTree(Node * pTree)
{
	if (pTree != nullptr) {
		destoryTree(pTree->getmpLeft());
		destoryTree(pTree->getmpRight());
		delete pTree;
	}
}

void BST::insert(string newString, int units, Node *& pTree)
{
	Node * pMem = new TransactionNode(newString, units);

	if (pTree == nullptr) {
		Node * pMem = new TransactionNode(newString, units);
		pTree = pMem;
	}
	else {
		if (units < (dynamic_cast<TransactionNode*>(pTree))->getUnits()) {
			insert(newString, units, (pTree->getmpLeft()));
		}
		else if (units >(dynamic_cast<TransactionNode*>(pTree))->getUnits()) {
			insert(newString, units, (pTree->getmpRight()));
		}
	}
}

void BST::findSmallest()
{
	findSmallest(mpRoot);
}

void BST::findLargest()
{
	findLargest(mpRoot);
}


void BST::findSmallest(Node * pTree)
{

	if (pTree->getmpLeft() == nullptr) {
		TransactionNode smallest = (dynamic_cast<TransactionNode&>(*pTree));
		cout << smallest.getmData() << " " << smallest.getUnits();
	}
	else {
		findSmallest(pTree->getmpLeft());
	}
}

void BST::findLargest(Node * pTree)
{
	if (pTree->getmpRight() == nullptr) {
		TransactionNode largest = (dynamic_cast<TransactionNode&>(*pTree));
		cout << largest.getmData() << " " << largest.getUnits();
	}
	else {
		findLargest(pTree->getmpRight());
	}
}
