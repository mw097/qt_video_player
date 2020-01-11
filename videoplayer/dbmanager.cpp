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
   QString hash = "HASH";
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
