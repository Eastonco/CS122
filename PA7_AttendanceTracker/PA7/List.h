#include "Node.h"

template <class T>
class List
{
public:
	List<T>();
	~List();

	Node<T> * getHeadPtr();
	void setHeadPtr(Node<T> * newHeadPtr);
	void InsertAtFront(T &newData);
	bool isEmpty();
	T dequeue();

private:
	Node<T> * mpHead;

	void deleteList();
};

template <class T>
List<T>::List()
{
	mpHead = nullptr;
}

template <class T>
List<T>::~List()
{
	this->deleteList();
}

template<class T>
Node<T>* List<T>::getHeadPtr()
{
	return mpHead;
}

template<class T>
void List<T>::setHeadPtr(Node<T> * newHeadPtr)
{
	this->mpHead = newHeadPtr;
}

template<class T>
void List<T>::InsertAtFront(T &newData)
{
	Node<T> *pMem = new Node<T>(newData);

	if (this->mpHead == nullptr) {
		mpHead = pMem;
	}
	else {
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}
}

template<class T>
bool List<T>::isEmpty()
{
	return this->mpHead == nullptr;
}

template<class T>
T List<T>::dequeue()
{
	T returnData;
	Node<T> *pTemp = nullptr;

	pTemp = this->mpHead;
	returnData = *(this->mpHead->getData());

	if (this->mpHead->getNextPtr() == nullptr) {
		this->mpHead = nullptr;
	}
	else {
		this->setHeadPtr(this->mpHead->getNextPtr());
	}
	delete pTemp;

	return returnData;
}

template<class T>
void List<T>::deleteList()
{
	while (!this->isEmpty()) {
		this->dequeue();
	}
}


