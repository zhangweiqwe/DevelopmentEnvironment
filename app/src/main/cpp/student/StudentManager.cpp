#include <list>
#include <iostream>
#include <ostream>
//
// Created by Administrator on 8:4.
//

#include "StudentManager.h"


void StudentManager::add(Student student) {
    auto it = students.begin();
    students.insert(it, student);
}

void StudentManager::remove(int id) {
    //删除
    for (auto it = students.begin(); it != students.end();) {
        Student student = (Student) *it;
        if (student.getId() != id)
            it++;
        else
            it = students.erase(it);//erase会销毁迭代器，并更新迭代器的值
    }
}

void StudentManager::update(int id, char *name) {
    for (auto it = students.begin(); it != students.end();) {

        Student student = (Student) *it;
        if (student.getId() != id)
            it++;
        else {
            it->setName(name);
            return;
        }

    }
}

Student *StudentManager::query(int id) {
    for (auto it = students.begin(); it != students.end();) {
        Student student = (Student) *it;
        if (student.getId() != id)
            it++;
        else
            return &*it;
    }

    return nullptr;
}


void StudentManager::printAllStudent() {
    cout << "-->" << endl;
    for (auto &i : students)
        printStudent(&(i));
    cout << "<--\n\n" << endl;
}


