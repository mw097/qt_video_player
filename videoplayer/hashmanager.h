#ifndef HASHMANAGER_H
#define HASHMANAGER_H

#include <QString>

class hashManager
{
public:
    hashManager();
    QString createHash(const QString &name);
};

#endif // HASHMANAGER_H
