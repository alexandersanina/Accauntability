#include "authentication.h"
#include <QDebug>

Authentication::Authentication()
{
    login_label = new QLabel("Login");
    password_label = new QLabel("Password");

    enter_button = new QPushButton("Enter");

    login_edit = new QLineEdit();
    password_edit = new QLineEdit();

    main_layout = new QVBoxLayout();
    login_layout = new QHBoxLayout();
    password_layout = new QHBoxLayout();
    enter_layout = new QHBoxLayout();

    this->setLayout(main_layout);

    main_layout->addLayout(login_layout);
    main_layout->addLayout(password_layout);
    main_layout->addLayout(enter_layout);

    login_layout->addWidget(login_label);
    login_layout->addWidget(login_edit);

    password_layout->addWidget(password_label);
    password_layout->addWidget(password_edit);

    enter_layout->addWidget(enter_button);

    this->setWindowTitle("Authentication");

    login_edit->setText("Admin");
    login_edit->setEnabled(false);
    //connect
    connect(enter_button, SIGNAL(clicked(bool)), this, SLOT(Authenticat()));
}

void Authentication::Authenticat()
{
    //QString login = login_edit->text();
    QString password = password_edit->text();

    if(password == "admin")
    {
        emit accepted();
    }
    password_edit->clear();
}
