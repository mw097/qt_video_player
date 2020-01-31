#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QThread>
#include <QList>
#include <QMessageBox>
using namespace std;

class DBManager
{
public:
    DBManager(const QString& path);
    bool addMovie(const QString& title);
    bool addBookmark(const QString& name, double time, QString title);
    bool addComment(const QString& name, int time, const QString& comment);
    bool getMovies();
    QString getMovieHash(const QString& title);    
    int getBookmarkTime(const QString &name);
    QStringList getBookmarks(const QString title);
    bool checkUniqueBookmark(const QString &bookmarkName, const QString &title);

    int getCommentTime(const QString& name);
    QString getCommentText(qint64& commentTime);
    QList<qint64> getComments(const QString& name);

private:
    QSqlDatabase db;
    bool checkUnique(const QString &title);
};

#endif // DBMANAGER_H
