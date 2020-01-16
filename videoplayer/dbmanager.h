#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMessageBox>

class DBManager
{
public:
    DBManager(const QString& path);
    bool addMovie(const QString& title);
    bool addBookmark(const QString& name, double time, QString title);
    bool addComment(const QString& name, double time, const QString& comment);
    bool getMovies();
    QString getMovieHash(const QString& title);
    double getBookmarkTime(const QString& name);
    int getMovieID(const QString &title);
    QStringList getBookmarks(const QString title);
private:
    bool checkUnique(const QString &title);
    bool checkUniqueBookmark(const QString &bookmarkName, const QString &title);
    QSqlDatabase db;
};

#endif // DBMANAGER_H
