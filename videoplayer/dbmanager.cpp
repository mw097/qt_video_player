#include "dbmanager.h"

DBManager::DBManager(const QString& path)
{
   db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName(path);

   if (!db.open())
   {
      qDebug() << "Error: connection with database failed";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
}

bool DBManager::addMovie(const QString& title)
{
   if(!checkUnique(title))
   {
       return false;
   }
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   QString hash = "HASH"; ///<--
   query.prepare("INSERT INTO file (hash, title) VALUES (:hash, :title)");
   query.bindValue(":hash", hash);
   query.bindValue(":title", title);
   if(query.exec())
   {
       success = true;
       qDebug() << "addMovie success";
   }
   else
   {
        qDebug() << "addMovie error:" << query.lastError();
   }

   return success;
}

bool DBManager::addBookmark(const QString &name, double time, QString title)
{
   // you should check if args are ok first...
   if(title == "")
   {
       QMessageBox msgBox;
       msgBox.setText("You cannot add bookmark when you don't watch any movie.");
       msgBox.exec();
       return false;
   }
   if(!checkUniqueBookmark(name, title))
   {
       QMessageBox msgBox;
       msgBox.setText("That bookmark name exists!");
       msgBox.exec();
       return false;
   }
   QSqlQuery query;
   query.prepare("INSERT INTO bookmark (name, time, title) VALUES (:name, :time, :title)");
   query.bindValue(":name", name);
   query.bindValue(":time", time);
   query.bindValue(":title", title);
   if(query.exec())
   {
        qDebug() << "addBookmark success";
        return true;
   }
   else
   {
        qDebug() << "addBookmark error:" << query.lastError();
        return false;
   }
}

QString DBManager::getMovieHash(const QString &title)
{
    QSqlQuery query;
    QString hash;
    query.prepare("SELECT hash FROM file WHERE id='"+title+"'");
    if(query.exec())
    {
        qDebug() << "getMovie success";
    }
    else
    {
         qDebug() << "getMovie error:" << query.lastError();
    }

    while (query.next())
    {
            hash = query.value(0).toString();
    }
    return hash;
}

int DBManager::getBookmarkTime(const QString &name)
{
    QSqlQuery query;
    int time = 0;
    query.prepare("SELECT time FROM bookmark WHERE name='"+name+"'");
    if(query.exec())
    {
        qDebug() << "getBookmarkTime success";
    }
    else
    {
        qDebug() << "getBookmarkTime error:" << query.lastError();
    }
    while (query.next())
    {
        time = query.value(0).toInt();
    }
    return time;
}

bool DBManager::addComment(const QString& hash, double time, const QString& comment)
{
    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query;
    query.prepare("INSERT INTO comments (hash, time, comment) VALUES (:hash, :time, :comment)");
    query.bindValue(":hash", hash);
    query.bindValue(":time", time);
    query.bindValue(":comment", comment);
    if(query.exec())
    {
        success = true;
        qDebug() << "addComment success";
    }
    else
    {
         qDebug() << "addComment error:" << query.lastError();
    }

    return success;
}

int DBManager::getMovieID(const QString &title)
{
    QSqlQuery query;
    int id = 0;
    query.prepare("SELECT id FROM file WHERE title='"+title+"'");
    if(query.exec())
    {
        qDebug() << "getMovieID success";
    }
    else
    {
         qDebug() << "getMovieID error:" << query.lastError();
    }
    while (query.next())
    {
            id = query.value(0).toInt();
            qDebug() << id;
    }
    return id;
}

QStringList DBManager::getBookmarks(const QString title)
{
    QSqlQuery query;
    QStringList bookmarkList;
    query.prepare("SELECT name FROM bookmark WHERE title='"+title+"'");
    if(query.exec())
    {
        qDebug() << "getBookmarks success";
    }
    else
    {
         qDebug() << "getBookmarks error:" << query.lastError();
    }
    while (query.next())
    {
        bookmarkList << query.value(0).toString();
    }

    return bookmarkList;
}

bool DBManager::checkUnique(const QString &title)
{
    QSqlQuery query;
    QString checkValue;
    query.prepare("SELECT title FROM file WHERE title='"+title+"'");
    if(query.exec())
    {
        qDebug() << "checkUnique success";
    }
    else
    {
         qDebug() << "checkUnique error:" << query.lastError();
    }
    while (query.next())
    {
        checkValue = query.value(0).toString();
    }
    if(checkValue == "")
    {
        return true;
    }
    return false;
}

bool DBManager::checkUniqueBookmark(const QString &bookmarkName, const QString &title)
{
    QSqlQuery query;
    QString checkValue;
    query.prepare("SELECT name FROM bookmark WHERE name='"+bookmarkName+"' AND title='"+title+"'");
    if(query.exec())
    {
        qDebug() << "checkUniqueBookmark success";
    }
    else
    {
        qDebug() << "checkUniqueBookmark error:" << query.lastError();
    }
    while (query.next())
    {
        checkValue = query.value(0).toString();
    }
    if(checkValue == "")
    {
        return true;
    }
}


