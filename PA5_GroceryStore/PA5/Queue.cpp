#include "Queue.h"

Queue::Queue(Node *newpHead, Node *newpTail)
{
	this->pHead = newpHead;
	this->pTail = newpTail;
}

Queue::~Queue()
{
	this->destroyQueue();
}

void Queue::enqueue(Data const &newData)
{

	Node *pMem = new Node(newData);

	if (pMem != nullptr) {
		if (this->pHead == nullptr) {
			this->setHeadPtr(pMem);
			this->setTailPtr(pMem);
		}
		else {
			this->pTail->setNextPtr(pMem);
			this->setTailPtr(pMem);
		}
	}
}

void Queue::dequeue()
{
	Node *pTemp = nullptr;

	pTemp = this->pHead;

	if (this->pHead == this->pTail) {
		this->pHead = this->pTail = nullptr;
	}
	else {
		this->setHeadPtr(this->pHead->getNextPtr());
	}

	delete pTemp;
}

bool Queue::isEmpty()
{
	return (this->pHead == nullptr);
}

void Queue::setHeadPtr(Node * const newHeadPtr)
{
	this->pHead = newHeadPtr;
}

void Queue::setTailPtr(Node * const newTailPtr)
{
	this->pTail = newTailPtr;
}

void Queue::destroyQueue()
{
	while (!this->isEmpty()) {
		this->dequeue();
	}
}

void Queue::printQueue()
{
	Node *pMem = pHead;
	while (pMem != nullptr) {
		cout << "|";
		pMem = pMem->getNextPtr();
	}
}

void Queue::checkQueue(Queue * myQueue, int time)
{
	if (myQueue->pHead != nullptr) {
		Node *pMem = myQueue->pHead;
		int num = myQueue->pHead->getServiceTime();
		if (pMem->getServiceTime() != 0) {
			myQueue->pHead->setServiceTimee(num-1);
		}
		else {
			myQueue->dequeue();
		}
	}
}

Node * Queue::getpHead()
{
	return pHead;
}

void Queue::runapp(int time)
{
	Queue q1, q2;
	int totalTime = 0;
	int cNum1 = 1, cNum2 = 1;
	char tmp = 'a';

	while (totalTime != time) {
		if (rand() % 2 == 0) {
			q1.enqueue(Data(cNum1, totalTime, 1));
			cNum1++;
		}
		if (rand() % 2 == 0) {
			q2.enqueue(Data(cNum2, totalTime, 2));
			cNum2++;
		}
		checkQueue(&q1, totalTime);
		checkQueue(&q2, totalTime);
		if (totalTime != 0 && totalTime % 10 == 0) {
			system("cls");
			cout << "Line 1: ";
			q1.printQueue();
			cout << endl << "Line 2: ";
			q2.printQueue();
			cout << endl << "Click any key to continue: " << endl;
			cin.get();
		}
		totalTime++;	
	}
}