#pragma once
#include "List.h"
template <class T>
class Headboard
{
private:
	List<T>* list;
	T criterio;
public:
	Headboard();
	void setCriterio(T c);
	T getCriterio();
	List<T>* getList();
};
template <class T>
Headboard<T>::Headboard()
{
	list = new List<T>();
}
template <class T>
void Headboard<T>::setCriterio(T c)
{
	this->criterio = c;
}
template <class T>
T Headboard<T>::getCriterio()
{
	return criterio;
}
template <class T>
List<T>* Headboard<T>::getList()
{
	return list;
}
