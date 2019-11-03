#include "Tree.h"
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	tree* root=nullptr;
	int size,i=0,level;
	cout << "������� ����������� ���������, ������� ������ �������� � ������:" << endl;
	cin >>size;
	int* data = new int[size];
	ifstream pout;
	pout.open("Text.txt");
	while(!pout.eof() || i==size-1)
	{
		pout >> data[i];
		root = add_node(data[i], root);
		i++;
	}
	pout.close();
	
	tree_print(root);
	cout << endl << "������� ������� �� ������� ������ ��������� ����������� �����������: level = ";
	cin >> level;
	cout<<endl<<lvl(root, level,0)<<endl;
	clear(root);
	root = nullptr;
	delete[] data;
}