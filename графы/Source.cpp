#include <iostream>
#include <fstream>
using namespace std;
//структура граф
// nv- номер вершины
//sv- степень вершины
// *ss - список смежности вершин
// *p- указатель для блока памяти под граф
struct graph 
{
	int nv,sv,*ss;
} *p=nullptr;
int n; // колличество вершин
bool* used=nullptr; // массив, который хранит значения пройденных вершин

bool input()
{
	ifstream fout;
	fout.open("Graph.txt");
	if (!fout.is_open())
	{
		cout << "невозможно открыть файл или он не существует!\n";
		return 0;
	}
	fout >> n;
	if (n == 0)
	{
		cout << "граф пуст !\n";
		fout.close();
		return 0;
	}
	else if (n == 1) // граф состоит из 1 вершины
	{
		p = new graph;
		fout >> p->nv>>p->sv;
		cout << "граф тривиален, следовательно не достижимых вершин до него не существует = 0\n ";
		fout.close();
		return 0;
	}
	p = new graph[n];
	used = new bool[n];
	for (int i = 0; i < n; i++)
	{
		fout >> p[i].nv >> p[i].sv;
		if (p[i].sv != 0) // есди sv!= 0 значит есть смежные вершины
		{
			p[i].ss = new int[p[i].sv];
			for (int j = 0; j < p[i].sv; j++)
				fout >> p[i].ss[j];
		} 
	}
	fout.close();
	return 1;
}

bool check_nv(int nv) // проверка на существование вершины в заданном графе
{
	int temp = 0;
	for (int i = 0; i < n; i++)
		if (nv == p[i].nv)
			temp++;
	if (temp)
		return 1;
	else
		return 0;
}

void clean_used()
{
	for (int i = 0; i < n; i++)
		used[i] = 0;
}

void DFS(int nv) 
{

	if (used[nv] == 0) //если марка = 0
	{
		used[nv] = 1; // метка равна 1
		for (int i = 0; i < p[nv].sv; i++)// пока меньше степени вершины
			DFS(p[nv].ss[i]); // функция вызывает сама
	}

}

int check(int i)//поиск не пройденных вершин

{
	if (!used[i])// если метка = 0 значит вершина не пройдена и нарушено условие связности
		return p[i].nv;
	else
		return -1;
}
bool clear() // чистим память
{
	if (n == 0)
		return 0;
	else if (n == 1)
	{
		delete p;
		p = nullptr;
	}
	else
	{
		for (int i = 0; i < n; i++)
			delete[] p[i].ss;
		delete[] p;
		delete[] used;
		p = nullptr;
		used = nullptr;
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int nv; // номер вершины
	if (!input())
	{
		system("pause"); 
		clear();
		exit(0);
	}
	cout << "введите номер вершины:" << endl;
	cin >> nv;
	cout << endl;
	clean_used();
	if (check_nv(nv))
	{
		cout << "вершины не смежные с данной :\n";
		DFS(nv);
		for (int i = 0; i < n; i++)
			if (check(i) != -1)
				cout << check(i) << "\t";
		cout << endl;
	}
	else
	{
		cout << "заданной вершины не существует в данном графе\n";
	}
	clear();
}