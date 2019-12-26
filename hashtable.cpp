#include "hashtable.h"

HashTable::HashTable(unsigned long long length)
{
    this->length = length;//初始化哈希表的长度
}

void HashTable::InitHashTable(){
    road = new Road[static_cast<unsigned long long>(this->length)];
    Road temp;
    for(unsigned long long i=0;i<this->length;i++){
        road[i] = temp;//初始化的每个元素结点的点个数为-1
    }
}

unsigned long long HashTable::Hash(int x,int y){
    return (static_cast<unsigned long long>(x+y)%length);

}

void HashTable::insertHash(Road r){
    unsigned long long addr = Hash(r.getEndPointA(),r.getEndPointB());
    while(static_cast<int>(road[addr].getPointNumber())!=-1){
        addr = (addr+1)%(this->length);
    }
    road[addr] = r;
}

int HashTable::equal(int x, int y,Road r){
    int flag = 0;
    if((x==r.getEndPointA()&&y==r.getEndPointB())||(y==r.getEndPointA()&&x==r.getEndPointB()))
        flag = 1;
    return flag;
}

unsigned long long HashTable::getLength() const
{
    return length;
}

void HashTable::setLength(unsigned long long value)
{
    length = value;
}



unsigned long long HashTable::searchHash(int x,int y){
    unsigned long long addr = Hash(x,y);
    while(!equal(x,y,road[addr])){
        addr = (addr+1)%(this->length);
    }
    return addr;
}
