#include "headers/myWidget.h"


myWidget::myWidget(){


    mainLayout = new QHBoxLayout;
    rightLayout = new QVBoxLayout;
    leftLayout = new QVBoxLayout;
    getInfo = new QPushButton("Get Info");
    addInfo =new QPushButton("Add info");
    left_name = new QLabel("Name");
    left_surname= new QLabel("Surname");
    left_job = new QLabel("Job");
    right_name = new QLabel("Name");
    right_surname= new QLabel("Surname");
    right_job = new QLabel("Job");

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

    setLayout(mainLayout);
    setFixedSize(500,500);
}
