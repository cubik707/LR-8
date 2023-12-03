#include "Menu.h"

void Menu::showContainerMenu()
{
	while (true)
	{
		cout << left << "Выберите контейнер: " << endl;
		cout << "1 - Очередь" << endl;
		cout << "2 - Стэк" << endl;
		cout << "3 - Приоритеная очередь" << endl;
		cout << "0 - Назад" << endl;
		int choice = Validator::getIntVar(0, 6);
		switch (choice) {
		case 1:
			showQueueMenu();
			break;
		case 2:
			showStackMenu();
			break;
		case 3:
			showPriorityQueueMenu();
			break;
		case 0:
			return;
		}
	}
}

void Menu::showQueueMenu()
{
	while (true)
	{
		cout << left << "Меню для очереди: " << endl;
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Удалить элемент" << endl;
		cout << "3 - Вывод данных" << endl;
		cout << "0 - Назад" << endl;
		int choice = Validator::getIntVar(0, 6);
		StudentQueue* queue = StudentQueue::getInstance();
		switch (choice) {
		case 1:
			queue->addToQueue(inputStudent());
			break;
		case 2:
			queue->removeFromQueue();
			cout << "Данные о студенте успешно удалены!" << endl;
			break;
		case 3:
			queue->printQueue();
			break;
		case 0:
			return;
		}
	}
}

void Menu::showStackMenu()
{
	while (true)
	{
		cout << left << "Меню для стека: " << endl;
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Удалить элемент" << endl;
		cout << "3 - Вывод данных" << endl;
		cout << "0 - Назад" << endl;
		int choice = Validator::getIntVar(0, 6);
		StudentStack* stack = StudentStack::getInstance();
		switch (choice) {
		case 1:
			stack->addToStack(inputStudent());
			break;
		case 2:
			stack->removeFromStack();
			cout << "Данные о студенте успешно удалены!" << endl;
			break;
		case 3:
			stack->printStack();
			break;
		case 0:
			return;
		}
	}
}

void Menu::showPriorityQueueMenu()
{
	while (true)
	{
		cout << left << "Меню для приоритетной очереди: " << endl;
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Удалить элемент" << endl;
		cout << "3 - Вывод данных" << endl;
		cout << "0 - Назад" << endl;
		int choice = Validator::getIntVar(0, 6);
		StudentPriorityQueue* pq = StudentPriorityQueue::getInstance();
		switch (choice) {
		case 1:
			pq->addToPriorityQueue(inputStudent());
			break;
		case 2:
			pq->removeFromPriorityQueue();
			cout << "Данные о студенте успешно удалены!" << endl;
			break;
		case 3:
			pq->printPriorityQueue();
			break;
		case 0:
			return;
		}
	}
}

Student Menu::inputStudent()
{
	string name;
	int group_num;

	cout << "Введите имя студента: ";
	cin.ignore();
	name = Validator::convertName();

	cout << "Введите номер группы: ";
	group_num = Validator::getIntVar(0, 999999);

	Student student(name, group_num);

	int choice;
	do {
		string subject;
		int grade;

		cout << "Введите предмет: ";
		subject = Validator::getValidStr();

		cout << "Введите оценку: ";
		grade = Validator::getIntVar(0, 10);

		student.addGrade(subject, grade);

		cout << "Хотите добавить еще оценку? (0 - нет /1 - да): ";
		choice = Validator::getIntVar(0, 1);
	} while (choice == 1);

	return student;
}
