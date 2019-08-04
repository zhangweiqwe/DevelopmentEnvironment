//
// Created by Administrator on 8:4.
//

#ifndef DEVELOPMENTENVIRONMENT_STUDENT_H
#define DEVELOPMENTENVIRONMENT_STUDENT_H


class Student {
public:
    //Student(char *name, unsigned short age);

    Student(int id, char *name, unsigned short age);

    int getId() const;

    //void setId(int id);

    char *getName() const;

    void setName(char *name);

    unsigned short getAge() const;

    void setAge(unsigned short age);

private:
    int id;
    char *name;
    unsigned short age;
};


#endif //DEVELOPMENTENVIRONMENT_STUDENT_H
