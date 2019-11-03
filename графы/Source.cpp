#include <iostream>
#include <fstream>
using namespace std;
//��������� ����
// nv- ����� �������
//sv- ������� �������
// *ss - ������ ��������� ������
// *p- ��������� ��� ����� ������ ��� ����
struct graph 
{
	int nv,sv,*ss;
} *p=nullptr;
int n; // ����������� ������
bool* used=nullptr; // ������, ������� ������ �������� ���������� ������

bool input()
{
	ifstream fout;
	fout.open("Graph.txt");
	if (!fout.is_open())
	{
		cout << "���������� ������� ���� ��� �� �� ����������!\n";
		return 0;
	}
	fout >> n;
	if (n == 0)
	{
		cout << "���� ���� !\n";
		fout.close();
		return 0;
	}
	else if (n == 1) // ���� ������� �� 1 �������
	{
		p = new graph;
		fout >> p->nv>>p->sv;
		cout << "���� ���������, ������������� �� ���������� ������ �� ���� �� ���������� = 0\n ";
		fout.close();
		return 0;
	}
	p = new graph[n];
	used = new bool[n];
	for (int i = 0; i < n; i++)
	{
		fout >> p[i].nv >> p[i].sv;
		if (p[i].sv != 0) // ���� sv!= 0 ������ ���� ������� �������
		{
			p[i].ss = new int[p[i].sv];
			for (int j = 0; j < p[i].sv; j++)
				fout >> p[i].ss[j];
		} 
	}
	fout.close();
	return 1;
}

bool check_nv(int nv) // �������� �� ������������� ������� � �������� �����
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

	if (used[nv] == 0) //���� ����� = 0
	{
		used[nv] = 1; // ����� ����� 1
		for (int i = 0; i < p[nv].sv; i++)// ���� ������ ������� �������
			DFS(p[nv].ss[i]); // ������� �������� ����
	}

}

int check(int i)//����� �� ���������� ������

{
	if (!used[i])// ���� ����� = 0 ������ ������� �� �������� � �������� ������� ���������
		return p[i].nv;
	else
		return -1;
}
bool clear() // ������ ������
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
	int nv; // ����� �������
	if (!input())
	{
		system("pause"); 
		clear();
		exit(0);
	}
	cout << "������� ����� �������:" << endl;
	cin >> nv;
	cout << endl;
	clean_used();
	if (check_nv(nv))
	{
		cout << "������� �� ������� � ������ :\n";
		DFS(nv);
		for (int i = 0; i < n; i++)
			if (check(i) != -1)
				cout << check(i) << "\t";
		cout << endl;
	}
	else
	{
		cout << "�������� ������� �� ���������� � ������ �����\n";
	}
	clear();
}