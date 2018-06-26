#include "student.h"

Student::Student(QString surname, QString name)
{
    this->surname = surname;
    this->name = name;
}

bool Student::SetMark(int numberLab, int mark)
{
    if(numberLab > 0 && MarkValidator(mark))
    {
        labMark.insert(numberLab, mark);
        return true;
    }
    else
    {
        return false;
    }
}

bool Student::MarkValidator(int mark)
{
    if(mark > 0 && mark < 11)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Student::IsEmptyField()
{
    if(name != "" || surname != "")
    {
        return true;
    }
    else
    {
        return false;
    }
}
