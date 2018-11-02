#include "headers/myWidget.h"
#include <QDebug>
#include <QSqlQuery>
myWidget::myWidget(){


    mainLayout = new QHBoxLayout;
    mainLayout2 = new QHBoxLayout;
    rightLayout = new QVBoxLayout;
    leftLayout = new QVBoxLayout;
    middleLayout = new QVBoxLayout;
    middleLayout2 = new QVBoxLayout;


    getInfo = new QPushButton("Get Info");
    addInfo =new QPushButton("Add info");
    left_name = new QLabel("Name");
    left_surname= new QLabel("Surname");
    left_job = new QLabel("Job");
    right_name = new QTextEdit();
    right_surname= new QTextEdit();
    right_job = new QTextEdit();
    resultField = new QTextEdit();
    reqField = new QTextEdit();

    rightLayout->addWidget(right_name);
    rightLayout->addWidget(right_surname);
    rightLayout->addWidget(right_job);


    leftLayout->addWidget(left_name);
    leftLayout->addWidget(left_surname);
    leftLayout->addWidget(left_job);

    mainLayout2->addLayout(leftLayout);
    mainLayout2->addLayout(rightLayout);

    middleLayout2->addLayout(mainLayout2);
    middleLayout2->addWidget(addInfo);

    middleLayout->addWidget(reqField);
    middleLayout->addWidget(getInfo);

    mainLayout->addLayout( middleLayout2);
    mainLayout->addLayout(middleLayout);
    mainLayout->addWidget(resultField);

    setLayout(mainLayout);

    right_job->setFixedHeight(60);
    right_name->setFixedHeight(60);
    right_surname->setFixedHeight(60);

    connect(getInfo,SIGNAL(clicked(bool)),this,SLOT(GetInfo()));
}

void myWidget::AddInfo(QString &name, QString &surname, QString &job)
{


}

void myWidget::GetInfo()
{
    resultField->clear();
    conn = new SQLConnector;
    QString req = reqField->toPlainText();
    auto res = conn->getInfo(req);
    while (res.next()) {
        QString myString = res.value(0).toString();
        resultField->moveCursor (QTextCursor::End);
        resultField->insertPlainText (myString+"\n");
        resultField->moveCursor (QTextCursor::End);
    }

    delete conn;
}
