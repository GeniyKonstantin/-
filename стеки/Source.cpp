#include "stack.h"

int main()
{
	setlocale(LC_ALL, "ru");
	stack s;
	int a,vibor;
	do
	{
		cout << "\n��������:\n1-������ �������� � ����\n2-��������� ���� �� ����\n3-������� ������� �� �����(������� �������� ������ �� ���� � ����������)\n 4-exit\n\n";
		cin >> vibor;
		switch (vibor)
		{
		case 1:
			cout << "������� ������������� �����\n";
			cin >> a;
			Push(&s, a);
			printStack(&s);
			break;
		case 2:
			cout<< "���� ����? 1-�� 0-���\t"<< Empty(&s) << endl;
			break;
		case 3:
			get_data(&s, a);
			printStack(&s);
			break;
		case 4:
			exit(0);
		}
	} while (vibor != 4);
}