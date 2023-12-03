#pragma once
#include "Student.h"
#include "Validator.h"
#include <queue>
#include <stack>

class StudentQueue
{
private:
    queue<Student> students;
    static StudentQueue* instance;
    StudentQueue() {}
public:
    static StudentQueue* getInstance();
    ~StudentQueue();


    void addToQueue(const Student& student);
    void removeFromQueue();
    void printQueue() const;

    void readFromFile();
    void fillQueue(ifstream& file);
    void writeInFile();
};

class StudentStack
{
private:
    stack<Student> students;
    static StudentStack* instance;
    StudentStack() {}
public:
    static StudentStack* getInstance();
    ~StudentStack();

    void addToStack(const Student& student);
    void removeFromStack();
    void printStack() const;

    void readFromFile();
    void fillStack(ifstream& file);
    void writeInFile();
};

class StudentPriorityQueue {
private:
    priority_queue<Student> students;
    static StudentPriorityQueue* instance;
    StudentPriorityQueue() {}
public:
    static StudentPriorityQueue* getInstance();
    ~StudentPriorityQueue();

    void addToPriorityQueue(const Student& student);
    void removeFromPriorityQueue();
    void printPriorityQueue() const;
    
    void readFromFile();
    void fillPriorityQueue(ifstream& file);
    void writeInFile();
};