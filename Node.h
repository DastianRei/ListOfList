#pragma once
#include <iostream>
using namespace std;
template <class T>
class Node
{
private:
	Node<T>* SIG;
	T elem;
public:
	Node(T elem, Node<T>* sig);
	~Node();
	Node* getSig();
	T getElem();
	void setElem(T elem);
	void setNext(Node<T>* sig);
};
template <class T>
Node<T>::Node(T elem, Node<T>* Sig)
{
	this->elem = elem;
	this->SIG = Sig;
}
template <class T>
Node<T>::~Node()
{

}
template <class T>
Node<T>* Node<T>::getSig()
{
	return SIG;
}
template <class T>
T Node<T>::getElem()
{
	return elem;
}
template <class T>
void Node<T>::setElem(T elem)
{
	this->elem = elem;
}
template <class T>
void Node<T>::setNext(Node<T>* sig)
{
	this->SIG = sig;
}