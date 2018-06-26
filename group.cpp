#include "group.h"

Group::Group(QString num)
{
    this->num = num;
    this->count_labs = 0;
}

bool Group::AddStudent(Student *student)
{
    if(student->IsEmptyField())
    {
        students_list.append(student);
        return true;
    }
    else
    {
        return false;
    }
}

bool Group::RemoveStudent(Student *student)
{
    return students_list.removeOne(student);
}

bool Group::SetCountLabs(int countLab)
{
    if(countLab >= 0)
    {
        count_labs = countLab;
        return true;
    }
    else
    {
        return false;
    }
}
