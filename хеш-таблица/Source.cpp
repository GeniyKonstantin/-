#include "hash-table.h"
#include <fstream>
int main()
{
	setlocale(LC_ALL, "ru");
	table a;
	string key, name;
	int count, size, i = 0;
	cin >> size;
	ifstream fout;
	fout.open("WORK.txt");
	while (!fout.eof() && i != size)
	{
		fout >> key;
		fout >> name;
		fout >> count;
		insert(a, key, count, name,0);
		i++;
	}
	printTable(a);
}