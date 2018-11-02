#ifndef __MYWIDGET__
#define __MYWIDGET__
#include <QWidget>

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include "headers/sqlConnector.h"
class myWidget:public QWidget
{
    Q_OBJECT
public:
    myWidget();
private:
    QPushButton *getInfo;
    QPushButton *addInfo;
    QHBoxLayout *mainLayout;
    QHBoxLayout *mainLayout2;
    QVBoxLayout *leftLayout;
    QVBoxLayout *middleLayout;
    QVBoxLayout *middleLayout2;
    QVBoxLayout *rightLayout;
    QLabel *left_name;
    QLabel *left_surname;
    QLabel *left_job;
    QTextEdit *right_name;
    QTextEdit *right_surname;
    QTextEdit *right_job;
    QTextEdit *resultField;
    QTextEdit *reqField;
    SQLConnector *conn;
public slots:
    void AddInfo(QString &name,QString &surname,QString &job);
    void GetInfo();
};

#endif
