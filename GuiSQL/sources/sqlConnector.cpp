#include "headers/sqlConnector.h"
#include <QString>
#include <QDebug>
#include <QSqlQuery>
SQLConnector::SQLConnector()
{

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(server);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(password);
    bool ok = db.open();
    qDebug()<<ok;

}

void SQLConnector::getInfo()
{
    QSqlQuery query(db);
    query.exec("SHOW TABLES");
//    qDebug()<<query.executedQuery();
    while (query.next()) {
        QString country = query.value(0).toString();
         qDebug()<<country;
    }
 }

SQLConnector::~SQLConnector()
{

}
