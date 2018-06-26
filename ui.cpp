#include "ui.h"
#include "ui_ui.h"

#include <QDebug>

UI::UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UI)
{
    ui->setupUi(this);

    aut_form = new Authentication();

    namegroup_label = new QLabel("Group Number:");
    name_label = new QLabel("Student Name:");
    surname_label = new QLabel("Student Surame:");

    namegroup_edit = new QLineEdit;
    name_edit = new QLineEdit;
    surname_edit = new QLineEdit;

    login_button = new QPushButton("Log In");
    logout_button = new QPushButton("Log Out");

    addgroup_button = new QPushButton("Create Group");
    addstudent_button = new QPushButton("Add Student");
    addlab_button = new QPushButton("Add Lab");
    deletelab_button = new QPushButton("Delete lab");
    savemark_button = new QPushButton("Save Mark");

    group_validator = new QIntValidator(100000, 99999999);
    student_validator = new QRegExpValidator(QRegExp("^[а-яА-Яa-zA-Z]+$"));

    group_table = new QTableWidget;
    students_table = new QTableWidget;

    main_layout = new QVBoxLayout;
    admin_layout = new QVBoxLayout;
    auth_layout = new QHBoxLayout;
    table_layout = new QHBoxLayout;
    addgroup_layout = new QHBoxLayout;
    addstudent_layout = new QHBoxLayout;
    lab_layout = new QHBoxLayout;
    mark_layout = new QHBoxLayout;

    this->setLayout(main_layout);
    main_layout->addLayout(auth_layout);
    main_layout->addLayout(admin_layout);
    main_layout->addLayout(table_layout);

    admin_layout->addLayout(addgroup_layout);
    admin_layout->addLayout(addstudent_layout);
    admin_layout->addLayout(lab_layout);
    admin_layout->addLayout(mark_layout);

    addgroup_layout->addWidget(namegroup_label);
    addgroup_layout->addWidget(namegroup_edit);
    addgroup_layout->addWidget(addgroup_button);

    addstudent_layout->addWidget(surname_label);
    addstudent_layout->addWidget(surname_edit);
    addstudent_layout->addWidget(name_label);
    addstudent_layout->addWidget(name_edit);
    addstudent_layout->addWidget(addstudent_button);

    lab_layout->addWidget(addlab_button);
    lab_layout->addWidget(deletelab_button);

    mark_layout->addWidget(savemark_button);

    auth_layout->addWidget(login_button);
    auth_layout->addWidget(logout_button);

    table_layout->addWidget(group_table);
    table_layout->addWidget(students_table);


    //connect
    connect(login_button, SIGNAL(clicked(bool)), this, SLOT(ShowAutForm()));
    connect(addgroup_button, SIGNAL(clicked(bool)), this, SLOT(AddGroup()));
    connect(group_table, SIGNAL(clicked(QModelIndex)), this, SLOT(ShowStudents()));
    connect(addstudent_button, SIGNAL(clicked(bool)), this, SLOT(AddStudent()));
    connect(addlab_button, SIGNAL(clicked(bool)), this, SLOT(AddLab()));
    connect(deletelab_button, SIGNAL(clicked(bool)), this, SLOT(DeleteLab()));
    connect(students_table, SIGNAL(cellChanged(int,int)), this, SLOT(ChangeMark(int,int)));
    connect(savemark_button, SIGNAL(clicked(bool)), this, SLOT(SaveMark()));

    connect(logout_button, &QPushButton::clicked,[this]()
    {
        HideAdminPanel();
    });

    connect(aut_form, &Authentication::accepted, [this]()
    {
        aut_form->close();
        ShowAdminPanel();
    });

    //table group
    group_table->setColumnCount(1);
    group_table->setHorizontalHeaderLabels(QStringList{"Group"});
    group_table->verticalHeader()->hide();
    group_table->setMaximumWidth(120);
    group_table->setMinimumWidth(120);

    //validate
    namegroup_edit->setValidator(group_validator);
    name_edit->setValidator(student_validator);
    surname_edit->setValidator(student_validator);

    //hide panel
    HideAdminPanel();
}

void UI::HideAdminPanel()
{
    namegroup_label->hide();
    namegroup_edit->hide();
    addgroup_button->hide();
    surname_label->hide();
    surname_edit->hide();
    name_edit->hide();
    name_label->hide();
    addstudent_button->hide();
    addlab_button->hide();
    deletelab_button->hide();
    savemark_button->hide();
}

void UI::ShowAdminPanel()
{
    namegroup_label->show();
    namegroup_edit->show();
    addgroup_button->show();
    surname_label->show();
    surname_edit->show();
    name_edit->show();
    name_label->show();
    addstudent_button->show();
    addlab_button->show();
    deletelab_button->show();
    savemark_button->show();
}

void UI::ChangeMark(int cr, int cc)
{
    if(cc > 1)
    {
        int mark = students_table->item(cr, cc)->text().toInt();
        if(mark > 0 && mark < 11 || students_table->item(cr, cc)->text() == "")
        {

        }
        else
        {
            QMessageBox::critical(this, "Error", "Bad input");
            students_table->item(cr, cc)->setText("");
        }
    }
}

void UI::AddLab()
{
    int num_group = group_table->currentRow();

    if(num_group != -1)
    {
        int count_col = ++groups_list.at(num_group)->count_labs + 2;

        students_table->setColumnCount(count_col);

        for(int i = 2; i < count_col; i++)
        {
            students_table->setHorizontalHeaderItem(i, new QTableWidgetItem("lab " + QString::number(i - 1)));
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No selected group");
    }
    //worker_xml = new WorkerXML(groups_list);
}

void UI::DeleteLab()
{
    int num_group = group_table->currentRow();

    if(num_group != -1 && groups_list.at(num_group)->count_labs != 0)
    {
        int count_col = --groups_list.at(num_group)->count_labs + 2;

        students_table->setColumnCount(count_col);

        for(int i = 2; i < count_col; i++)
        {
            students_table->setHorizontalHeaderItem(i, new QTableWidgetItem("lab " + QString::number(i - 1)));
        }

        int count_student = groups_list.at(num_group)->students_list.count();
        for(int i = 0; i < count_student; i++)
        {
            groups_list.at(num_group)->students_list.at(i)->labMark.remove(count_col - 1);
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No selected group");
    }
}

void UI::UpdateStudent(int num_group)
{    
    students_table->clear();
    int len = groups_list.at(num_group)->students_list.count();
    int count_col = groups_list.at(num_group)->count_labs + 2;
    int count_lab = groups_list.at(num_group)->count_labs;

    //table studens
    students_table->setColumnCount(count_col);
    students_table->setHorizontalHeaderLabels(QStringList{"Surname", "Name"});

    for(int i = 2; i < count_col; i++)
    {
        students_table->setHorizontalHeaderItem(i, new QTableWidgetItem("lab " + QString::number(i - 1)));
    }

    students_table->setRowCount(0);

    for(int i = 0; i < len; i++)
    {
        students_table->setRowCount(students_table->rowCount() + 1);

        students_table->setItem(i, 0, new QTableWidgetItem(groups_list.at(num_group)->students_list.at(i)->surname));
        students_table->setItem(i, 1, new QTableWidgetItem(groups_list.at(num_group)->students_list.at(i)->name));
        for(int j = 0; j < count_lab; j++)
        {
            int mark = groups_list.at(num_group)->students_list.at(i)->labMark.value(j + 1);
            //qDebug() << i <<j+1 << mark;
            if(mark != 0)
            {
                //qDebug() << i <<j+2 << mark;
                students_table->setItem(i, j+2, new QTableWidgetItem(QString::number(mark)));
            }
        }
    }
}

void UI::SaveMark()
{
    int num_group = group_table->currentRow();

    if(num_group != -1)
    {
        int sCount = students_table->rowCount(),
            cCount = students_table->columnCount();

        //clear marks
        for(int i = 0; i < sCount; i++)
        {
            groups_list.at(num_group)->students_list.at(i)->labMark.clear();
        }

        for(int s = 0; s < sCount; s++)
        {
            for(int c = 2; c < cCount; c++)
            {
                if(students_table->item(s, c))
                {
                    int mark = students_table->item(s, c)->text().toInt();

                    if(mark != 0)
                    {
                        //qDebug()<<mark<<"mark";
                        groups_list.at(num_group)->students_list.at(s)->labMark.insert(c - 1, mark);
                    }
                }
            }
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No selected group");
    }
}

void UI::AddStudent()
{
    int num_group = group_table->currentRow();

    if(num_group != -1)
    {
        QString name = name_edit->text();
        QString surname = surname_edit->text();

        groups_list.at(num_group)->students_list.append(new Student(surname, name));

        UpdateStudent(num_group);
    }
    else
    {
        QMessageBox::critical(this, "Error", "No selected group");
    }
}

void UI::ShowStudents()
{
    int num_group = group_table->currentRow();
    //qDebug()<<num_group;
    UpdateStudent(num_group);
}

void UI::AddGroup()
{
    int pos = 0;
    QString num = namegroup_edit->text();

    if(group_validator->validate(num, pos) == QValidator::Acceptable)
    {
        table_item = new QTableWidgetItem(num);
        group_table->setRowCount(group_table->rowCount() + 1);
        group_table->setItem(group_table->rowCount() - 1, 0, table_item);

        groups_list.append(new Group(num));
    }
    else
    {
        QMessageBox::critical(this, "Error", "Group number must contain at least 6 characters");
    }
}

void UI::ShowAutForm()
{
    aut_form->show();
}

UI::~UI()
{
    delete ui;
}
