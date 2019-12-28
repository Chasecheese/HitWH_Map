#include "list.h"

List::List()
{
    length =0;
}

bool List::ListInsert(int i, int e){
    int k;
    if(length == 40)
        return false;
    if(i<1||i>length+1)
        return false;
    if(i<=length){
        for(k=length-1;k>=i-1;k--)
            data[k+1] = data[k];
    }
    data[i-1]=e;
    length++;
    return true;
}

int List::ListLength(){
    return length;
}

bool List::GetElem(int i, int &e){
    if(length==0||i<1||i>length)
        return false;
    e = data[i-1];
    return true;
}

bool List::ListDelete(int i, int &e){
    int k;
    if(length==0)
        return false;
    if(i<1||i>length)
        return false;
    e = data[i-1];
    if(i<length){
        for(k=i;k<length;k++){
            data[k-1] = data[k];
        }
    }
    length--;
    return true;
}

int List::getLength() const
{
    return length;
}

void List::setLength(int value)
{
    length = value;
}

List::~List(){

}
