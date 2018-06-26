#ifndef UI_H
#define UI_H

#include "group.h"
#include "workerxml.h"

#include <QWidget>
#include <QPushButton>
#include <authentication.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QLabel>
#include <QList>
#include <QMessageBox>


namespace Ui {
class UI;
}

class UI : public QWidget
{
    Q_OBJECT

public:
    explicit UI(QWidget *parent = 0);
    ~UI();

private:
    QIntValidator *group_validator;
    QRegExpValidator *student_validator;

    WorkerXML *worker_xml;
    QPushButton *login_button,
                *logout_button,
                *addgroup_button,
                *addstudent_button,
                *addlab_button,
                *deletelab_button,
                *savemark_button;

    Authentication *aut_form;

    QTableWidget *group_table,
                 *students_table;

    QTableWidgetItem *table_item;

    QVBoxLayout *main_layout,
                *admin_layout;

    QHBoxLayout *table_layout,
                *auth_layout,
                *addgroup_layout,
                *addstudent_layout,
                *lab_layout,
                *mark_layout;

    QLabel *namegroup_label,
           *name_label,
           *surname_label;

    QLineEdit *namegroup_edit,
              *name_edit,
              *surname_edit;

    QList<Group*> groups_list;

    void UpdateStudent(int);
    void ShowAdminPanel();
    void HideAdminPanel();

public slots:
    void ShowAutForm();
    void AddGroup();
    void ShowStudents();
    void AddStudent();
    void AddLab();
    void DeleteLab();
    void ChangeMark(int,int);
    void SaveMark();

private:
    Ui::UI *ui;
};

#endif // UI_H
