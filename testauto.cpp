#include "testauto.h"

TestAuto::TestAuto(QObject *parent) : QObject(parent)
{

}

void TestAuto::AddStudent_empty_name_surname_false()
{
    Group *group = new Group("1234567");
    Student *student = new Student("", "");
    QCOMPARE(group->AddStudent(student), false);
    delete group;
}

void TestAuto::AddStudent_normal_name_surname_true()
{
    Group *group = new Group("1234567");
    Student *student = new Student("San", "San");
    QCOMPARE(group->AddStudent(student), true);
    delete group;
}

void TestAuto::RemoveStudent_that_not_on_the_list_false()
{
    Group *group = new Group("1234567");
    group->AddStudent(new Student("Samsa", "San"));
    Student *student = new Student("Naruto", "Johnny");
    QCOMPARE(group->RemoveStudent(student), false);
    delete group;
}

void TestAuto::RemoveStudent_that_is_in_the_list_true()
{
    Group *group = new Group("1234567");
    Student *student = new Student("Naruto", "Johnny");
    group->AddStudent(student);
    QCOMPARE(group->RemoveStudent(student), true);
    delete group;
}

void TestAuto::SetCountLabs_invalid_value_false()
{
    Group *group = new Group("1234567");
    QCOMPARE(group->SetCountLabs(-3), false);
    delete group;
}

void TestAuto::SetCountLabs_normal_value_true()
{
    Group *group = new Group("1234567");
    QCOMPARE(group->SetCountLabs(1), true);
    delete group;
}

void TestAuto::MarkValidator_invalid_value_false()
{
    Student *student = new Student("Naruto", "Johnny");
    QCOMPARE(student->MarkValidator(0), false);
    delete student;
}

void TestAuto::MarkValidator_normal_value_true()
{
    Student *student = new Student("Naruto", "Johnny");
    QCOMPARE(student->MarkValidator(5), true);
    delete student;
}

void TestAuto::SetMark_invalid_value_false()
{
    Student *student = new Student("Naruto", "Johnny");
    QCOMPARE(student->SetMark(0, -2), false);
    delete student;
}

void TestAuto::SetMark_normal_value_true()
{
    Student *student = new Student("Naruto", "Johnny");
    QCOMPARE(student->SetMark(1, 6), true);
    delete student;
}

void TestAuto::IsEmptyField_empty_value_false()
{
    Student *student = new Student("", "");
    QCOMPARE(student->IsEmptyField(), false);
    delete student;
}

void TestAuto::IsEmptyField_normal_value_true()
{
    Student *student = new Student("Naruto", "Johnny");
    QCOMPARE(student->IsEmptyField(), true);
    delete student;
}


