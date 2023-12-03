#include <iostream>
#include "Menu.h"
#include <Windows.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	StudentQueue::getInstance()->readFromFile();
	StudentStack::getInstance()->readFromFile();
	StudentPriorityQueue::getInstance()->readFromFile();

	Menu menu;
	menu.showContainerMenu();

	StudentQueue::getInstance()->writeInFile();
	StudentStack::getInstance()->writeInFile();
	StudentPriorityQueue::getInstance()->writeInFile();
}

