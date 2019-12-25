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

unsigned long long HashTable::Hash(Road r){
    unsigned long long x = static_cast<unsigned long long>(r.getEndPointA());
    unsigned long long y = static_cast<unsigned long long>(r.getEndPointB());
    return (x+y)%length;

}

void HashTable::insertHash(Road r){
    unsigned long long addr = Hash(r);
    while(static_cast<int>(road[addr].getPointNumber())==-1){
        addr = (addr+1)%(this->length);
    }
    road[addr] = r;
}

int HashTable::equal(Road A, Road B){
    int flag = 1;
    if(A.getEndPointA()!=B.getEndPointA())
        flag = 0;
    if(A.getEndPointB()!=B.getEndPointB())
        flag = 0;
    return flag;

}


unsigned long long HashTable::searchHash(Road r){
    unsigned long long addr = Hash(r);

    while(!equal(r,road[addr])){
        addr = (addr+1)%(this->length);
    }

    return addr;

}
