#pragma once
#include "Node.h"
template <class T>
class List
{
private:
	Node<T>* first;
	Node<T>* last;
	int tam;
public:
	List();
	~List();
	int getTam();
	void pushFront(T elem);
	void pushLast(T elem);
	bool DeleteFirst();
	void showList(void (*f)(T*));
	void showList();
	void ordenar(bool (comparar)(T*, T*));
	T SearchNoRec(T elem);
	T SearchRec(T elem, int pos);
	T SearchPos(int pos);
	T operator[](int pos);
	bool DeleteLast();
	bool DeleteElem(T Elem);
};
template <class T>
List<T>::List()
{
	first = NULL;
	last = NULL;
	tam = 0;
}
template <class T>
List<T>::~List()
{

}
template <class T>
int List<T>::getTam()
{
	return tam;
}
template <class T>
void List<T>::pushFront(T elem)
{
	Node<T>* aux;
	if (first == NULL)
	{
		first = new Node<T>(elem, NULL);
		last = first;
	}
	else
	{
		aux = new Node<T>(elem, first);
		first = aux;
	}
}


template <class T>
void List<T>::pushLast(T elem)
{
	Node<T>* aux;
	if (first == NULL)
	{
		first = new Node<T>(elem, NULL);
		tam+=1;
	}
	else
	{
		aux = first;
		while (aux->getSig() != NULL)
		{
			aux = aux->getSig();
		}
		aux = new Node<T>(elem, NULL);
	}
}
template <class T>
bool List<T>::DeleteFirst()
{
	bool res;
	if (first == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (first == last) //Solo uno
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			Node<T>* aux;
			aux = first->getSig();
			delete first;
			first = aux;
			first->setNext(aux);
		}
	}
	return res;
}
template <class T>
T List<T>::SearchRec(T elem, int pos)
{
	T* value = NULL;
	Node<T>* aux = first;
	if (*aux->getElem() == elem)
	{
		value = aux->getElem();
	}
	else if (aux != NULL)
	{
		SearchRec(elem, pos + 1);
		aux = aux->getSig();
	}
	return value;
}
template <class T>
void List<T>::showList(void (*f)(T*))
{
	Node<T>* aux = first;
	if (first == NULL)
	{
		cout << "Empty List";
	}
	while (aux != NULL)
	{
		(*f)(aux->getElem());
		aux = aux->getSig();
	}
}
template <class T>
void List<T>::showList()
{
	Node<T>* aux = first;

	while (aux != NULL)
	{
		cout << aux->getElem()<<endl;
		aux = aux->getSig();
	}
}
template <class T>
T List<T>::SearchNoRec(T elem)
{
	Node<T>* aux = first;
	while (aux != NULL)
	{
		if (aux->getElem() == elem)
		{
			return aux->getElem();
		}
		aux = aux->getSig();
	}
	return NULL;
}
template <class T>
T List<T>::SearchPos(int pos)
{
	int posS = 0;
	Node<T>* aux = first;
	while (aux != NULL)
	{
		if (posS == pos)
		{
			return aux->getElem();
		}
		aux = aux->getSig();
		posS++;
	}
	return NULL;
}
template <class T>
T List<T>::operator[](int pos)
{
	int posS = 0;
	Node<T>* aux = first;
	while (aux != NULL)
	{
		if (posS == pos)
		{
			return aux->getElem();
		}
		aux = aux->getSig();
		posS++;
	}

}
template <class T>
void List<T>::ordenar(bool (comparar)(T*, T*))
{
	Node<T>* primer = first;
	Node<T>* aux = NULL;
	T* auxEncon;
	while (primer != NULL)
	{
		aux = primer->getSiguiente();
		while (aux != NULL)
		{
			if ((*comparar)(primer->getElem(), aux->getElem()))
			{
				auxEncon = aux->getElem();
				aux->setDato(primer->getDato());
				primer->setDato(auxEncon);
			}
			aux = aux->getSiguiente();
		}
		primer = primer->getSiguiente();
	}

}
template <class T>
bool List<T>::DeleteLast()
{
	bool res;
	if (first == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			Node<T>* aux = first;
			while (aux->getSig()->getSig() != NULL)
			{
				aux = aux->getSig();
			}
			delete last;
			last = aux;
			last->setNext(NULL);
		}
	}
	return res;
}

template <class T>
bool List<T>::DeleteElem(T elemento)
{
	bool func = false;
	if (first == NULL)
	{
		func = false;
	}
	else
	{
		if (first->getElem() == elemento)
		{
			func = DeleteFirst();
		}
		else if (last->getElem() == elemento)
		{
			func = DeleteLast();
		}
		else
		{
			Node<T>* aux = first;
			while (aux->getSig()->getElem() != elemento && aux->getSig() != last)
			{
				aux = aux->getSig();
				if (aux->getSig() == last && aux->getSig()->getElem() == elemento)
				{
					delete aux->getSig();
					last = aux;
					last->setElem(NULL);
					func = true;
				}
				else
				{
					if (aux->getSig()->getElem() == elemento)
					{
						Node<T>* ayuda = aux->getSig()->getSig();
						delete aux->getSig();
						aux->setNext(ayuda);
						func = true;
					}
				}
			}
		}
	}
	return func;
}