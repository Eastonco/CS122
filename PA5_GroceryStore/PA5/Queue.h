#include "Node.h"

class Queue
{
public:
	Queue(Node *newpHead = nullptr, Node *newpTail = nullptr);
	~Queue();

	void enqueue(const Data &newData);
	void dequeue();
	bool isEmpty();
	Node *getpHead();

	void setHeadPtr(Node * const newHeadPtr);
	void setTailPtr(Node * const newTailPtr);


	void runapp(int time);
	void printQueue();
	void checkQueue(Queue * myQueue, int time);

private:
	Node *pHead;
	Node *pTail;

	void destroyQueue();
};
