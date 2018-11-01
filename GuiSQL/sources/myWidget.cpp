#include "headers/myWidget.h"
#include <QDebug>

myWidget::myWidget(){


    mainLayout = new QHBoxLayout;
    rightLayout = new QVBoxLayout;
    leftLayout = new QVBoxLayout;
    getInfo = new QPushButton("Get Info");
    addInfo =new QPushButton("Add info");
    left_name = new QLabel("Name");
    left_surname= new QLabel("Surname");
    left_job = new QLabel("Job");
    right_name = new QTextEdit();
    right_surname= new QTextEdit();
    right_job = new QTextEdit();
    resultField = new QTextEdit();

    rightLayout->addWidget(right_name);
    rightLayout->addWidget(right_surname);
    rightLayout->addWidget(right_job);
    rightLayout->addWidget(getInfo);

    leftLayout->addWidget(left_name);
    leftLayout->addWidget(left_surname);
    leftLayout->addWidget(left_job);
    leftLayout->addWidget(addInfo);

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->addWidget(resultField);

    setLayout(mainLayout);

    right_job->setFixedHeight(50);
    right_name->setFixedHeight(50);
    right_surname->setFixedHeight(50);
    //    setFixedSize(500,500);
    connect(getInfo,SIGNAL(clicked(bool)),this,SLOT(GetInfo()));
}

void myWidget::AddInfo(QString &name, QString &surname, QString &job)
{


}

void myWidget::GetInfo()
{
    QString name = right_name->toPlainText();
    qDebug()<<name;
//    conn = new SQLConnector;
//    conn->getInfo(name);
}
