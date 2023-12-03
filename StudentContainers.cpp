#include "StudentContainers.h"

StudentQueue* StudentQueue::instance = nullptr;

StudentQueue* StudentQueue::getInstance()
{
    if (!instance) {
        instance = new StudentQueue();
    }
    return instance;

}

StudentQueue::~StudentQueue()
{
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void StudentQueue::addToQueue(const Student& student)
{
	students.push(student);
}

void StudentQueue::removeFromQueue()
{
	if (!students.empty()) {
		students.pop();
	}
}

void StudentQueue::printQueue() const
{
    int length = 137, i = 1;
    printLine(length);
    queue<Student> temp = students;
    while (!temp.empty()) {
        cout << left << setw(5) << "| " + to_string(i++);
        temp.front().print();
        temp.pop();
    }
    printLine(length);
}

void StudentQueue::readFromFile()
{
    ifstream file;
    try
    {
        file.open("students.txt");

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла.");
        }
        if (file.good())
        {
            fillQueue(file);
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
        exit(0);
    }
}

void StudentQueue::fillQueue(ifstream& file)
{
    while (!students.empty()) {
        students.pop();
    }

    Student student;
    while (file >> student) {
        addToQueue(student);
    }

    if (!file.eof() && file.fail()) {
        throw runtime_error("Ошибка в чтении строки.");
    }
}

void StudentQueue::writeInFile()
{
    ofstream file;
    try
    {
        file.open("studentsQueue.txt", ios::out | ios::trunc);

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла для записи.");
        }

        while (!students.empty()) {
            file << students.front();
            students.pop();
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        exit(0);
    }
}

StudentStack* StudentStack::instance = nullptr;

StudentStack* StudentStack::getInstance()
{
    if (!instance) {
        instance = new StudentStack();
    }
    return instance;
}

StudentStack::~StudentStack()
{
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void StudentStack::addToStack(const Student& student)
{
    students.push(student);
}

void StudentStack::removeFromStack()
{
    if (!students.empty()) {
        students.pop();
    }
}

void StudentStack::printStack() const
{
    int length = 137, i = 1;
    printLine(length);
    stack<Student> temp = students;
    while (!temp.empty()) {
        cout << left << setw(5) << "| " + to_string(i++);
        temp.top().print();
        temp.pop();
    }
    printLine(length);
}

void StudentStack::readFromFile()
{

    ifstream file;
    try
    {
        file.open("students.txt");

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла.");
        }
        if (file.good())
        {
            fillStack(file);
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
        exit(0);
    }
}

void StudentStack::fillStack(ifstream& file)
{
    while (!students.empty()) {
        students.pop();
    }

    Student student;
    while (file >> student) {
        addToStack(student);
    }

    if (!file.eof() && file.fail()) {
        throw runtime_error("Ошибка в чтении строки.");
    }
}

void StudentStack::writeInFile()
{
    ofstream file;
    try
    {
        file.open("studentsStack.txt", ios::out | ios::trunc);

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла для записи.");
        }

        while (!students.empty()) {
            file << students.top();
            students.pop();
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        exit(0);
    }
}

StudentPriorityQueue* StudentPriorityQueue::instance = nullptr;

StudentPriorityQueue* StudentPriorityQueue::getInstance()
{
    if (!instance) {
        instance = new StudentPriorityQueue();
    }
    return instance;
}

StudentPriorityQueue::~StudentPriorityQueue()
{
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void StudentPriorityQueue::addToPriorityQueue(const Student& student)
{
    students.push(student);
}

void StudentPriorityQueue::removeFromPriorityQueue()
{
    if (!students.empty()) {
        students.pop();
    }
}

void StudentPriorityQueue::printPriorityQueue() const
{
    int length = 137, i = 1;
    printLine(length);
    priority_queue<Student> temp = students;
    while (!temp.empty()) {
        cout << left << setw(5) << "| " + to_string(i++);
        temp.top().print();
        temp.pop();
    }
    printLine(length);
}

void StudentPriorityQueue::readFromFile()
{
    ifstream file;
    try
    {
        file.open("students.txt");

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла.");
        }
        if (file.good())
        {
            fillPriorityQueue(file);
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
        exit(0);
    }
}

void StudentPriorityQueue::fillPriorityQueue(ifstream& file)
{
    while (!students.empty()) {
        students.pop();
    }

    Student student;
    while (file >> student) {
        addToPriorityQueue(student);
    }

    if (!file.eof() && file.fail()) {
        throw runtime_error("Ошибка в чтении строки.");
    }
}

void StudentPriorityQueue::writeInFile()
{
    ofstream file;
    try
    {
        file.open("studentsPriorityQueue.txt", ios::out | ios::trunc);

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла для записи.");
        }

        while (!students.empty()) {
            file << students.top();
            students.pop();
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        exit(0);
    }
}
