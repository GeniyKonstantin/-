#include "List.h"
int main()
{ 
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int size;
	do
	{
	cout << "������� ���������� ��������� � �����(������ ���� 2 ��� ������ ���������):\n";
	cin >> size;
	} while (size <= 1);
	for (int i = 0; i < size; i++) 
	{
		push_back(rand() % 20);
		cout << at(i) << "\t";
	}
	cout << endl<< "����� ������������������ : "<<endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << at(i) - at(size - 1) << "\t";
	}
	return 1;
}