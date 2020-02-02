#include "Header.h"

class Node
{
public:
	Node(string newData = "");
	~Node();

	void setmData(string newData);
	void setmpLeft(Node * newLeft);
	void setmpRight(Node * newRight);

	string getmData();
	Node *& getmpLeft();
	Node *& getmpRight();

	virtual void printData() = 0;

private:
	string mData;
	Node * mpLeft;
	Node * mpRight;
};
