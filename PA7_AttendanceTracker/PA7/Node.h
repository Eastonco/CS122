#include "Data.h"

template <class T>
class Node
{
public:
	Node<T>(T &newData);
	~Node();

	Node<T> * getNextPtr();
	void setNextPtr(Node<T> * pMem);
	T * getData();

private:
	Node<T> * mpNext;
	T mData;
};

template <class T>
Node<T>::Node(T &newData)
{
	this->mpNext = nullptr;
	this->mData = newData;
}

template <class T>
Node<T>::~Node()
{
}

template<class T>
Node<T> * Node<T>::getNextPtr()
{
	return this->mpNext;
}

template<class T>
void Node<T>::setNextPtr(Node<T>* pMem)
{
	mpNext = pMem;
}

template<class T>
T * Node<T>::getData()
{
	return &this->mData;
}
