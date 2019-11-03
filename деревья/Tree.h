#pragma once
#include <iostream>
using namespace std;

struct tree
{
	int data;
	tree* left, * right;
};

tree* add_node(int data, tree* p) {
	if (p == nullptr) { // Если дерева нет, то формируем корень
		p = new tree; // память под узел
		p->data = data;   // поле данных
		p->left = nullptr;
		p->right = nullptr; // ветви инициализируем пустотой
	}
	else  if (data < p->data)   // условие добавление левого потомка
		p->left = add_node(data, p->left);
	else    // условие добавление правого потомка
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
		count += lvl(p->left, level, i + 1); // прибавляем 1 если дошли до нужного уровня
		count += lvl(p->right, level, i + 1);
	}
	return (i > 0) ? 0 : count;   //Определяет что вернет рекурсия. Если рекурсия на самом начальном уровне, то возвращает количество элементов, если глубже - то 0 (чтобы не произошло лишних суммирований)
}

void tree_print(tree* p)
{
	if (p != nullptr)  //Пока не встретится пустой узел
	{
		cout << p->data<<"\t"; //Отображаем корень дерева
		tree_print(p->left); //Рекурсивная функция для левого поддерева
		tree_print(p->right); //Рекурсивная функция для правого поддерева
	}
}

void clear(tree* p)  // чистит дерево
{
	if (p != nullptr) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
}