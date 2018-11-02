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

 QSqlQuery SQLConnector::getInfo(QString &req)
{
    QSqlQuery query(db);
    query.exec(req);
    return query;
 }

SQLConnector::~SQLConnector()
{
    db.close();
}
