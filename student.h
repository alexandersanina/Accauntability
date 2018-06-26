#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QMap>

class Student
{
public:
    Student(QString, QString);

    QString surname,
            name;

    QMap<int, int> labMark;

    bool SetMark(int, int);
    bool MarkValidator(int);
    bool IsEmptyField();

};

#endif // STUDENT_H
