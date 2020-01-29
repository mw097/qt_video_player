#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QThread>
#include <QList>
using namespace std;

class DBManager
{
public:
    DBManager(const QString& path);
    bool addMovie(const QString& title);
    bool addBookmark(const QString& name, double time);
    bool addComment(const QString& name, int time, const QString& comment);
    bool getMovies();
    QString getMovieHash(const QString& title);
    double getBookmarkTime(const QString& name);

    int getCommentTime(const QString& name);
    QString getCommentText(qint64& commentTime);
    QList<qint64> getComments(const QString& name);

private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
