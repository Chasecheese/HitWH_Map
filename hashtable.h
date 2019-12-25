#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QPoint>
#include <road.h>

class HashTable
{
public:
    HashTable(unsigned long long length);

    void InitHashTable();

    unsigned long long Hash(Road);

    void insertHash(Road);

    unsigned long long searchHash(Road);

    int equal(Road,Road);

private:
    Road* road;
    unsigned long long length;
};

#endif // HASHTABLE_H
