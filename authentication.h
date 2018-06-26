#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class Authentication : public QDialog
{
  Q_OBJECT

public:
    Authentication();

private:
    QLabel *login_label,
           *password_label;

    QLineEdit *login_edit,
              *password_edit;

    QVBoxLayout *main_layout;

    QHBoxLayout *login_layout,
                *password_layout,
                *enter_layout;

    QPushButton *enter_button;

private slots:
    void Authenticat();
};

#endif // AUTHENTICATION_H
