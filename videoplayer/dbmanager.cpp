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

bool DBManager::addBookmark(const QString &name, double time, int movieid)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO bookmark (name, time, movie_id) VALUES (:name, :time, :movieid)");
   query.bindValue(":name", name);
   query.bindValue(":time", time);
   query.bindValue(":movie_id", movieid);
   if(query.exec())
   {
       success = true;
       qDebug() << "addBookmark success";
   }
   else
   {
        qDebug() << "addBookmark error:" << query.lastError();
   }

   return success;
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

double DBManager::getBookmarkTime(const QString &name)
{
    QSqlQuery query;
    double time = .0;
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
            time = query.value(0).toDouble();
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


