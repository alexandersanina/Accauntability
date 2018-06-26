#include "ui.h"
#include <QApplication>
#include <testauto.h>
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTest::qExec(new TestAuto(), argc, argv);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    UI w;
    w.show();

    return a.exec();
}

TEST(TestGroup, AddStudent_empty_name_surname_false)
{
    Group *group = new Group("1234567");
    Student *student = new Student("", "");
    bool result = group->AddStudent(student);
    ASSERT_FALSE(result);
    delete group;
}

TEST(TestGroup, AddStudent_normal_name_surname_true)
{
    Group *group = new Group("1234567");
    Student *student = new Student("San", "San");
    bool result = group->AddStudent(student);
    ASSERT_TRUE(result);
    delete group;
}

TEST(TestGroup, RemoveStudent_that_not_on_the_list_false)
{
    Group *group = new Group("1234567");
    group->AddStudent(new Student("Samsa", "San"));
    Student *student = new Student("Naruto", "Johnny");
    bool result = group->RemoveStudent(student);
    ASSERT_FALSE(result);
    delete group;
}

TEST(TestGroup, RemoveStudent_that_is_in_the_list_true)
{
    Group *group = new Group("1234567");
    Student *student = new Student("Naruto", "Johnny");
    group->AddStudent(student);
    bool result = group->RemoveStudent(student);
    ASSERT_TRUE(result);
    delete group;
}

TEST(TestGroup, SetCountLabs_invalid_value_false)
{
    Group *group = new Group("1234567");
    bool result = group->SetCountLabs(-3);
    ASSERT_FALSE(result);
    delete group;
}

TEST(TestGroup, SetCountLabs_normal_value_true)
{
    Group *group = new Group("1234567");
    bool result = group->SetCountLabs(1);
    ASSERT_TRUE(result);
    delete group;
}

TEST(TestStudent, MarkValidator_invalid_value_false)
{
    Student *student = new Student("Naruto", "Johnny");
    bool result = student->MarkValidator(0);
    ASSERT_FALSE(result);
    delete student;
}

TEST(TestStudent, MarkValidator_normal_value_true)
{
    Student *student = new Student("Naruto", "Johnny");
    bool result = student->MarkValidator(5);
    ASSERT_TRUE(result);
    delete student;
}

TEST(TestStudent, SetMark_invalid_value_false)
{
    Student *student = new Student("Naruto", "Johnny");
    bool result = student->SetMark(0, -2);
    ASSERT_FALSE(result);
    delete student;
}

TEST(TestStudent, SetMark_normal_value_true)
{
    Student *student = new Student("Naruto", "Johnny");
    bool result = student->SetMark(1, 6);
    ASSERT_TRUE(result);
    delete student;
}

TEST(TestStudent, IsEmptyField_empty_value_false)
{
    Student *student = new Student("", "");
    bool result = student->IsEmptyField();
    ASSERT_FALSE(result);
    delete student;
}

TEST(TestStudent, IsEmptyField_normal_value_true)
{
    Student *student = new Student("Naruto", "Johnny");
    bool result = student->IsEmptyField();
    ASSERT_TRUE(result);
    delete student;
}
