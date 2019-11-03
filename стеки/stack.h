#pragma once
#include <iostream>
#define size 5
using namespace std;

struct stack
{
	int top=0;
	int data[size];
};

void Push(stack *s, float data)  //поместить элемент в стек
{
	if (s->top < size)
	{
		s->data[s->top++] = data;
	}
	else
		cout << "стек переполнен\n";
}

bool Empty(const stack* s)  //проверка на пустоту
{
	if (s->top != 0)
		return false; else return true;
}


void get_data(stack* s, int& data)
{
	if (!Empty(s))
	{
		data = s->data[--s->top];
	}
}

void printStack(const stack* s)    // распечатать содержимое стека
{
	cout << "содержимое стека\t";
	if (!Empty(s))
	{
		for(int i=s->top-1;i>=0;--i)
			cout << s->data[i]<<"\t";
	}
	else
	{
		cout << "стек пуст";
	}
	cout << endl;
}