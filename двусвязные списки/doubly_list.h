#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

struct doubly_list
{
	doubly_list* pNext;
	doubly_list* pPrev;
	char data;
	int size = 0;
} *head = nullptr;

// добавляет элемент в конец списка
void push_back(const char data)
{
	if (head == nullptr)
	{
		head = new doubly_list;
		head->data = data;
		head->pNext = nullptr;
	}
	else if (head->pNext == nullptr)
	{
		head->pNext = new doubly_list;
		head->pNext->data = data;
		head->pNext->pPrev = head;
		head->pNext->pNext = head;
	}
	else
	{
		doubly_list* p = head;
		for (int i = 0; i < head->size - 1; i++)
			p = p->pNext;
		doubly_list* temp = p;
		p->pNext = new doubly_list;
		p = p->pNext;
		p->pPrev = temp;
		p->data = data;
		p->pNext = head;
		head->pPrev = p;
		temp=p = nullptr;
	}
	head->size++;
}
//возвращает данные указанного элемента
char at(const int nomer)
{
	// если список пуст или номер элемента отрицательный
	if (!head || nomer < 0)
		return 0;
	// если номер элемента последний в списке и список состоит из 3 или более элементов
	if (nomer == head->size - 1 && head->size>2)
	{
		return head->pPrev->data;
	}
	//если номер элемента находится ближе к началу то начинаем поиск с начала
	else if (nomer < head->size && nomer <= head->size/2)
	{
		doubly_list* p = head;
		for (int i = 0; i < nomer; i++)
		{
			p = p->pNext;
		}
		return p->data;
	}
	//если номер элемента находится ближе к концу то начинаем поиск с конца
	else if (nomer < head->size && nomer > head->size / 2)
	{
		doubly_list* p = head;
		for (int i = 0; i < head->size-nomer; i++)
		{
			p = p->pPrev;
		}
		return p->data;
	}
}
// удаляет выбранный элемент
bool erase(const int nomer)
{
	// если номер элемента отрицательный
	if (head->size - nomer < 0)
		return false;
	// если в списке нет элементов
	if (head == nullptr)
	{
		return false;
	}
	// если номер элемента 1 в списке и размер списка равен 1, то есть состоит только из головного элемента
	else if (nomer == 0 && head->size == 1)
	{
		delete head;
		head = nullptr;
		return true;
	}
	// если номер элемента первый в списке
	else if (nomer == 0)
	{
		doubly_list* p = head->pNext;
		doubly_list* temp = head->pPrev;
		p->size = --head->size;
		delete head;
		head = p;
		head->pNext = head->pNext;
		if (head->size > 1)
		{
			head->pPrev = temp;
		}
		temp = p = nullptr;
		return true;
	}
	// если номер элемента является последним в списке
	else if (nomer == head->size - 1)
	{
		doubly_list* p = head->pPrev;
		doubly_list* temp = p->pPrev;
		delete p;
		temp->pNext = head;
		head->pPrev = temp;
		head->size--;
		p = temp = nullptr;
		return true;
	}
	//если номер элемента находится ближе к началу то начинаем поиск с начала
	else if(nomer <= head->size / 2)
	{
		doubly_list* p = head;
		for (int i = 0; i < nomer - 1; i++)
		{
			p = p->pNext;
		}
		doubly_list* temp = p->pNext;
		p->pNext = (p->pNext->pNext);
		p->pNext->pPrev = p;
		delete temp;
		p=temp = nullptr;
		head->size--;
		return true;
	}
	//если номер элемента находится ближе к концу то начинаем поиск с конца
	else if (nomer > head->size / 2)
	{
		doubly_list* p = head;
		for (int i = 0; i < head->size - nomer+1; i++)
		{
			p = p->pPrev;
		}
		doubly_list* temp = p->pNext;
		p->pNext = (p->pNext->pNext);
		p->pNext->pPrev = p;
		delete temp;
		p = temp = nullptr;
		head->size--;
		return true;
	}
}
//чистит список
void list_clear()
{
	while (head)
		erase(0);
}
