#include "Table.h"
#include <fstream>
int main()
{
	setlocale(LC_ALL, "ru");
	table a;
	string key, name;
	int count,size,i=0;
	cin >> size;
	ifstream fout;
	fout.open("WORK.txt");
	while (!fout.eof() && i != size)
	{
		fout >> key;
		fout >> name;
		fout >> count;
		insert(a, key, count, name);
		i++;
	}
	/*for (int i=0;i<a.n;i++)
		cout << a.arr[i].key << endl;
	*/
	printTable(a);
	fout.close();
}