#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QPoint>
#include <road.h>

class HashTable
{
public:
    HashTable(unsigned long long length);

    void InitHashTable();

    unsigned long long Hash(int x,int y);
    unsigned long long HashUnique(int x, int y);

    void insertHash(Road);

    unsigned long long searchHash(int x,int y);

    int equal(int,int,Road);

    Road* road;

    unsigned long long getLength() const;
    void setLength(unsigned long long value);

private:

    unsigned long long length;

};

#endif // HASHTABLE_H
