#pragma once
#include "Headboard.h"
#define TAM 60
template <class T>
class ListOfList
{
private:
	Headboard<T> vec[TAM];
	int first;
	int last;
public:
	ListOfList();
	~ListOfList();
	void pushFront(T elemPrin,T elemSec);
	void show();
	T search(T elemPrin, T elemSec);
	void deleteElemSec(T elemPrin, T elemSec);
	int Cont(T elem);
};
template <class T>
ListOfList<T>::ListOfList()
{
	first = -1;
	last = -1;
}
template <class T>
ListOfList<T>::~ListOfList()
{

}
template <class T>
void ListOfList<T>::pushFront(T elemPrin, T elemSec)
{
	bool resp = false;
	if (first == -1 and last == -1)
	{
		first = TAM / 2;
		last = TAM / 2;
		vec[first].setCriterio(elemPrin);
		vec[first].getList()->pushFront(elemSec);
	}
	else
	{
		int aux = first;
		while (elemPrin != vec[aux].getCriterio() and aux != last)
		{
			if (aux == TAM - 1)
			{
				aux = 0;
			}
			else { aux += 1; }
		}
		if (elemPrin == vec[aux].getCriterio())
		{
			vec[aux].getList()->pushFront(elemSec);
		}
		else
		{
			if (first == 0)
			{
				if (last == TAM - 1)
				{
					first = TAM - 1;
					resp = true;
				}
			}
			else
			{
				if (last != first - 1)
				{
					first = first - 1;
					resp = true;
				}
			}
		}
		
	}
	if (resp == true)
	{
		vec[first].setCriterio(elemPrin);
		vec[first].getList()->pushFront(elemSec);
	}
}
template <class T>
void ListOfList<T>::show()
{
	int aux = first;
	if (first == -1 and last == -1)
	{
		cout << "Lista Vacia"<<endl;
	}
	else
	{
		while(aux!=last)
		{
			
			cout << "ElemPrin: "<<vec[aux].getCriterio() << endl;
			cout << "The elements are: " << endl;
			vec[aux].getList()->showList();
			if (aux == TAM - 1) { aux = 0; }
			else { aux+=1; }
		}
		cout << vec[aux].getCriterio() << endl;
		vec[aux].getList()->showList();
	}
}
template <class T>
T ListOfList<T>::search(T elemPrin, T elemSec)
{
	T dato;
	if (first == -1 && last == -1)
	{
		return NULL;
	}
	else
	{
		int aux = first;
		while (aux != last)
		{
			if (aux != TAM - 1)
			{
				if (elemPrin == vec[aux].getCriterio())
				{
					dato= vec[aux].getList()->SearchNoRec(elemSec);
				}
				aux+=1;
			}
			else
			{
				if (elemPrin == vec[aux].getCriterio())
				{
					dato = vec[aux].getList()->SearchNoRec(elemSec);
				}
				aux = 0;
			}
		}
		if (aux == last)
		{
			if (elemPrin == vec[aux].getCriterio())
			{
				dato = vec[aux].getList()->SearchNoRec(elemSec);
			}
		}
	}
	return dato;
}
template <class T>
void ListOfList<T>::deleteElemSec(T elemPrin, T elemSec)
{
	bool elim;
	if (first == -1 && last == -1)
	{
		elim = false;
	}
	else
	{
		int aux = first;
		while (aux != last)
		{
			if (aux != TAM - 1)
			{
				if (elemPrin == vec[aux].getCriterio())
				{
					elim = vec[aux].getList()->DeleteElem(elemSec);
				}
				aux+=1;
			}
			else
			{
				if (elemPrin == vec[aux].getCriterio())
				{
					elim = vec[aux].getList()->DeleteElem(elemSec);
				}
				aux = 0;
			}
		}
		if (aux == last)
		{
			if (elemPrin == vec[aux].getCriterio())
			{
				elim = vec[aux].getList()->DeleteElem(elemSec);
			}
		}
	}
	
}
template <class T>
int ListOfList<T>::Cont(T elem)
{
	T dato;
	int cont = 0;
	int i = 0;
	if (first == -1 && last == -1)
	{
		return NULL;
	}
	else
	{
		int aux = first;
		while (aux != last)
		{
			if (aux != TAM - 1)
			{
				if (elem == vec[aux].getCriterio())
				{
					if (vec[aux].getList()->SearchPos(i)!="\n")
					{
						cont++;
						i++;
					}
				}
				aux += 1;
			}

		}
	}
	return cont;
}
	
