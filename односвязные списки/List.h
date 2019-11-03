#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct list
{
	list* pNext;
	float data;
	int size = 0;
} *head = nullptr;

//возвращает данные указанного элемента
float at(const int nomer) 
{

	if (nomer < head->size) {
		list* p = head;
		for (int i = 0; i < nomer; i++)
		{
			p = p->pNext;
		}
		return p->data;
	}
} 
// удаляет последний элемент
void pop_back()
{
	if (head->size > 1)
	{
		list* p = head;
		for (int i = 1; i < head->size; i++)
			p = p->pNext;
		head->size--;
		delete p;
		p = nullptr;
	}
	else
	{
		head->size--;
		delete head;
		head = nullptr;
		
	}
}
// удаляет выбранный элемент
bool erase(const int nomer)
{
	if (head == nullptr)
	{
		return false;
	}
	else if (nomer == 0 && head->size == 1)
	{
		delete head;
		head = nullptr;
		return true;
	}
	else if (nomer == 0)
	{
		list* p = head->pNext;
		p->size = --head->size;
		delete head;
		head = p;
		return true;
	}
	else if (nomer == head->size - 1)
	{
		list* p = head;
		for (int i = 1; i < nomer - 1; i++)
		{
			p = p->pNext;
			if (p == nullptr)
			{
				return false;
			}
		}
		list* temp = p->pNext;
		p->pNext = nullptr;
		delete temp;
		temp = nullptr;
		head->size--;
		return true;
	}
	else
	{
		list* p = head;
		for (int i = 1; i < nomer-1; i++)
		{
			p = p->pNext;
			if (p == nullptr)
			{
				return false;
			}
		}
		list* temp = p->pNext;
		p->pNext = (p->pNext->pNext);
		delete temp;
		temp = nullptr;
		head->size--;
		return true;
	}
}
// чистит список
void list_clear()
{

	while (head != nullptr)
	{
		erase(0);
	}
}
// добавляет элемент в конец списка
void push_back(const float data)
{
	if (head == nullptr)
	{
		head = new list;
		head->pNext = nullptr;
		head->data = data;
	}
	else
	{
		list* p = head;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = new list;
		p = p->pNext;
		p->data = data;
		p->pNext = nullptr;
	}
	head->size++;
}
int get_size() {
	if (head != nullptr)
		return head->size;
	else
		return 0;
}
//  добавляет перед nomer новый элемент 
bool insert(const float data, const int nomer)
{

	if (head == nullptr)
	{
		head = new list;
		head->pNext = nullptr;
		head->data = data;
		head->size++;
		return true;
	}
	else if (nomer==0)
	{
		list* p = head;
		head = new list;
		head->pNext = p;
		head->data = data;
		head->size = p->size;
		head->size++;
		return true;
	}
	else 
	{
		list* p = head;
		for (int i = 1; i < nomer-1; i++)
		{
			p = p->pNext;
			if (p == nullptr)
			{
				push_back(data);
				return false;
			}
		}
		list* temp = new list;
		temp->pNext = p->pNext;
		p->pNext = temp;
		temp->data = data;
		head->size++;
		return true;

	}
}
// возвращает первый элемент списка
float first()
{
	if(head!=nullptr)
	 return at(0);
}
// возвращает последний элемент списка
float last() {
	if (head != nullptr)
		return at(head->size - 1);
}

