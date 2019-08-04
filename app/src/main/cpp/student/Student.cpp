//
// Created by Administrator on 8:4.
//

#include "Student.h"


//这是构造器
Student::Student(int id, char *name, unsigned short age) : id(id), name(name), age(age) {}

//下面是 get 或 set方法
int Student::getId() const {
    return id;
}

char *Student::getName() const {
    return name;
}

void Student::setName(char *name) {
    Student::name = name;
}

unsigned short Student::getAge() const {
    return age;
}

void Student::setAge(unsigned short age) {
    Student::age = age;
}
//end