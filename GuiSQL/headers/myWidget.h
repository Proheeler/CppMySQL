#ifndef __MYWIDGET__
#define __MYWIDGET__
#include <QWidget>

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
class myWidget:public QWidget
{
    Q_OBJECT
public:
    myWidget();
private:
    QPushButton *getInfo;
    QPushButton *addInfo;
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QLabel *left_name;
    QLabel *left_surname;
    QLabel *left_job;
    QLabel *right_name;
    QLabel *right_surname;
    QLabel *right_job;

};

#endif
