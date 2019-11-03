#pragma once
#include <iostream>
#include <string>
#define razmer 17
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
	int n = 0;
};

int Fhash(string key, int a)
{
	int sum = 0;
	for (int k = 0; k < key.length(); k++)
		sum = sum + int(key[k]);
	return  (sum+a) % razmer;
}


bool insert(table& p, string key, int count, string name, int a)
{
	int Nkey = Fhash(key,a);
	//cout << Nkey << endl;
	if (p.arr[Nkey].key == "")
	{
		p.arr[Nkey].key = key;
		p.arr[Nkey].count = count;
		p.arr[Nkey].name = name;
		p.n++;
		return true;
	}
	else if (p.arr[Nkey].key == key)
	{
		p.arr[Nkey].count += count;
		return true;
	}
	else if (p.n >= razmer - 1)
	{
		cout << "таблица заполнена";
		return false;
	}
	else
	{
		a++;
		insert(p,key, count, name,a);
		return false;
	}
}

void printTable(table t)
{
	for (int i = 0; i < razmer; i++)
	{
		if(t.arr[i].key!="")
		cout << t.arr[i].key << "\t" << t.arr[i].name << "\t" << t.arr[i].count << endl;
	}
}