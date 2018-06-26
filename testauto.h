#ifndef TESTAUTO_H
#define TESTAUTO_H

#include <QObject>
#include <QTest>
#include <ui.h>
#include <group.h>
#include <student.h>

class TestAuto : public QObject
{
    Q_OBJECT

public:
    explicit TestAuto(QObject *parent = nullptr);

private slots:
    void AddStudent_empty_name_surname_false();
    void AddStudent_normal_name_surname_true();
    void RemoveStudent_that_not_on_the_list_false();
    void RemoveStudent_that_is_in_the_list_true();
    void SetCountLabs_invalid_value_false();
    void SetCountLabs_normal_value_true();
    void MarkValidator_invalid_value_false();
    void MarkValidator_normal_value_true();
    void SetMark_invalid_value_false();
    void SetMark_normal_value_true();
    void IsEmptyField_empty_value_false();
    void IsEmptyField_normal_value_true();
};

#endif // TESTAUTO_H
