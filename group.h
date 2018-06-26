#ifndef GROUP_H
#define GROUP_H

#include "student.h"

#include <QString>
#include <QList>

class Group
{
public:
    Group(QString);
    QString num;
    QList<Student*> students_list;
    int count_labs;

    bool AddStudent(Student*);
    bool RemoveStudent(Student*);
    bool SetCountLabs(int);

};

#endif // GROUP_H
