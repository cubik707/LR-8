#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;
class Student
{
private:
    string name;
    int group_num;
    multimap<string, int> grades;
public:
    Student() : name(""), group_num(0) {}

    Student(const string& studentName, int studentGroup)
        : name(studentName), group_num(studentGroup) {}

    // �������
    string getName() const { return name; }
    int getGroupNum() const { return group_num; }
    multimap<string, int>& getGrades() { return grades; }
    const multimap<string, int>& getGrades() const { return grades; }

    // �������
    void setName(const string& studentName) { name = studentName; }
    void setGroupNum(int studentGroup) { group_num = studentGroup; }

    void addGrade(const string& subject, int grade);
    void print() const;

    bool operator<(const Student& other) const;
    bool operator==(const Student& other) const;

    friend ostream& operator<<(ostream& out, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};

