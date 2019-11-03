#include "doubly_list.h"

int main()
{
	setlocale(LC_ALL, "ru");
	int size,i=0;
	cin >> size;
	char* arr = new char[size];
	ifstream fout;
	fout.open("Text.txt");
	while(!fout.eof() && i!=size)
	{
		fout >> arr[i];
		push_back(arr[i]);
		cout << at(i) << "\t";
		i++;
	}
	fout.close();
	cout << endl;
	for (int i = 0;i < head->size; i++)
	{
		if (int(at(i)) < 65 || int(at(i)) > 122)
		{
			if (i == 0)
				erase(i--);
			else
			{
				erase(i--);
				erase(i--);
			}
		}
		if (head == nullptr)
			break;
	}
	cout << "==============================================================================="<<endl;
	if (head!=nullptr)
	{
		for (int i = 0; i < head->size; i++)
		{
			cout << at(i) << "\t";
		}
	}
	else
	{
		cout << "список пуст" << endl;
	}
	list_clear();
	delete[] arr;
}