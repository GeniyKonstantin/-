#pragma once
#include <iostream>
#include <string>
#define razmer 15
using namespace std;

struct elem
{
	string key;
	int count;
	string name;
};

struct table
{
	elem arr[razmer];
	int n=0;
};

bool insert(table &p,string key,int count,string name)
{
	if (p.n == 0)
	{
		p.arr[0].key = key;
		p.arr[0].name = name;
		p.arr[0].count = count;
		p.n=1;
		return true;
	}
	else if (p.n == razmer - 1)
	{
		cout << "\nТаблица переполнена\n";
		return false;
	}
	else if (p.arr[0].key<key)
	{
		for (int i = 0; i < p.n; i++)
		{
			p.arr[p.n - i] = p.arr[p.n - i - 1];
		}
		p.arr[0].key = key;
		p.arr[0].count = count;
		p.arr[0].name = name;
		p.n++;
		return true;
	}
	else
	{
		for (int i = 1; i < p.n; i++)
		{
			if (p.arr[i - 1].key == key)
			{
			p.arr[i - 1].count += count;
			return true;
			}
			else if (p.arr[i-1].key > key && p.arr[i].key < key)
			{
				for (int j = 0; j <=p.n-i; j++)
				{
					p.arr[p.n-j] = p.arr[p.n - j-1];
				}
				p.arr[i].key = key;
				p.arr[i].name = name;
				p.arr[i].count = count;
				p.n++;
				return true;
			}
		}
		p.arr[p.n].key = key;
		p.arr[p.n].name = name;
		p.arr[p.n].count = count;
		p.n++;
		return true;
	}
}

void printTable(table t)
{
	for (int i = 0; i < t.n; i++)
	{
		cout << t.arr[i].key << "\t" << t.arr[i].name << "\t" << t.arr[i].count<<endl;
	}
}