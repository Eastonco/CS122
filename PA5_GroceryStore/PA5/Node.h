#include "Data.h"

class Node
{
public:
	Node(Data const &newData);
	~Node();

	Node *getNextPtr() const;
	void setNextPtr(Node *newNextPtr);
	int getTotalTime() const;
	int getServiceTime() const;
	void setServiceTimee(int i);
private:
	Data *pData;
	Node *pNext;
};
