#include "Table.h"
#include <fstream>
int main()
{
	setlocale(LC_ALL, "ru");
	table a;
	string key, name;
	int count, size, i = 0,price;
	cin >> size;
	ifstream fout;
	fout.open("WORK.txt");
	while (!fout.eof() && i != size)
	{
		fout >> key;
		fout >> name;
		fout >> count;
		fout >> price;
		insert(a, key, count, name,price);
		i++;
	}
	printTable(a);
	cout << endl;
	ShellSort(a, a.n);
	printTable(a);
	fout.close();
}