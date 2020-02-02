#include "TransactionNode.h"

class BST
{
public:
	BST();
	~BST();

	Node * getRootPtr() const;
	void setRootPtr(Node * newNode);

	void inOrderTraversal();
	void insert(string newItem, int units);
	void findSmallest();
	void findLargest();

private:
	Node * mpRoot;

	void inOrderTraversal(Node * pRoot);
	void destoryTree(Node * pTree);
	void insert(string newItem, int units, Node *& treeRoot);
	void findSmallest(Node * pTree);
	void findLargest(Node * pTree);
};
