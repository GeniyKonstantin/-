#pragma once
#include <iostream>
using namespace std;

struct tree
{
	int data;
	tree* left, * right;
};

tree* add_node(int data, tree* p) {
	if (p == nullptr) { // ���� ������ ���, �� ��������� ������
		p = new tree; // ������ ��� ����
		p->data = data;   // ���� ������
		p->left = nullptr;
		p->right = nullptr; // ����� �������������� ��������
	}
	else  if (data < p->data)   // ������� ���������� ������ �������
		p->left = add_node(data, p->left);
	else    // ������� ���������� ������� �������
		p->right = add_node(data, p->right);
	return(p);
}

int lvl(tree* p, int level, int i)
{
	static int count = 0;

	if (p ==nullptr)
		return 0;
	else if (i == level)
		return 1;
	else {
		count += lvl(p->left, level, i + 1); // ���������� 1 ���� ����� �� ������� ������
		count += lvl(p->right, level, i + 1);
	}
	return (i > 0) ? 0 : count;   //���������� ��� ������ ��������. ���� �������� �� ����� ��������� ������, �� ���������� ���������� ���������, ���� ������ - �� 0 (����� �� ��������� ������ ������������)
}

void tree_print(tree* p)
{
	if (p != nullptr)  //���� �� ���������� ������ ����
	{
		cout << p->data<<"\t"; //���������� ������ ������
		tree_print(p->left); //����������� ������� ��� ������ ���������
		tree_print(p->right); //����������� ������� ��� ������� ���������
	}
}

void clear(tree* p)  // ������ ������
{
	if (p != nullptr) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
}