#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

class DBManager
{
public:
    DBManager(const QString& path);
    bool addMovie(const QString& title);
    bool addBookmark(const QString& name, double time);
private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
