#include "stack.h"

int main()
{
	setlocale(LC_ALL, "ru");
	stack s;
	int a,vibor;
	do
	{
		cout << "\nвыберете:\n1-ввести элементы в стек\n2-проверить пуст ли стек\n3-удалить элемент из стека(сначала поместим данные из него в переменную)\n 4-exit\n\n";
		cin >> vibor;
		switch (vibor)
		{
		case 1:
			cout << "введите целочисленное число\n";
			cin >> a;
			Push(&s, a);
			printStack(&s);
			break;
		case 2:
			cout<< "стек пуст? 1-да 0-нет\t"<< Empty(&s) << endl;
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