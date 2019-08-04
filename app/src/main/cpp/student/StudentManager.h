#include <list>
#include <ostream>
#include "Student.h"
//
// Created by Administrator on 8:4.
//

#ifndef DEVELOPMENTENVIRONMENT_STUDENTMANAGER_H
#define DEVELOPMENTENVIRONMENT_STUDENTMANAGER_H


using namespace std;

class StudentManager {
private:
    StudentManager() {};
    list<Student> students;

public:
    static StudentManager &GetInstance() {
        static StudentManager instance;
        //cout<<&instance<<endl;
        return instance;
    }


    static void printStudent(Student *student) {
        if (student != NULL) {
            cout << student << student->getId() << "\t" << student->getName() << "\t"
                 << student->getAge()
                 << endl;

        }
    }

    /*static void printAllStudent() {
        cout << "-->" << endl;
        for (auto &i : StudentManager::GetInstance().students)
            printStudent(&(i));
        cout << "<--\n\n" << endl;
    }*/

    void add(Student student);

    void remove(int id);

    void update(int id, char *name);

    Student *query(int id);


    void printAllStudent();

};


#endif //DEVELOPMENTENVIRONMENT_STUDENTMANAGER_H
