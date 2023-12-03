#include "Menu.h"

void Menu::showContainerMenu()
{
	while (true)
	{
		cout << left << "�������� ���������: " << endl;
		cout << "1 - �������" << endl;
		cout << "2 - ����" << endl;
		cout << "3 - ����������� �������" << endl;
		cout << "0 - �����" << endl;
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
		cout << left << "���� ��� �������: " << endl;
		cout << "1 - �������� �������" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ����� ������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 6);
		StudentQueue* queue = StudentQueue::getInstance();
		switch (choice) {
		case 1:
			queue->addToQueue(inputStudent());
			break;
		case 2:
			queue->removeFromQueue();
			cout << "������ � �������� ������� �������!" << endl;
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
		cout << left << "���� ��� �����: " << endl;
		cout << "1 - �������� �������" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ����� ������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 6);
		StudentStack* stack = StudentStack::getInstance();
		switch (choice) {
		case 1:
			stack->addToStack(inputStudent());
			break;
		case 2:
			stack->removeFromStack();
			cout << "������ � �������� ������� �������!" << endl;
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
		cout << left << "���� ��� ������������ �������: " << endl;
		cout << "1 - �������� �������" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ����� ������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 6);
		StudentPriorityQueue* pq = StudentPriorityQueue::getInstance();
		switch (choice) {
		case 1:
			pq->addToPriorityQueue(inputStudent());
			break;
		case 2:
			pq->removeFromPriorityQueue();
			cout << "������ � �������� ������� �������!" << endl;
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

	cout << "������� ��� ��������: ";
	cin.ignore();
	name = Validator::convertName();

	cout << "������� ����� ������: ";
	group_num = Validator::getIntVar(0, 999999);

	Student student(name, group_num);

	int choice;
	do {
		string subject;
		int grade;

		cout << "������� �������: ";
		subject = Validator::getValidStr();

		cout << "������� ������: ";
		grade = Validator::getIntVar(0, 10);

		student.addGrade(subject, grade);

		cout << "������ �������� ��� ������? (0 - ��� /1 - ��): ";
		choice = Validator::getIntVar(0, 1);
	} while (choice == 1);

	return student;
}
