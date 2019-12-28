#ifndef List_H
#define List_H



class List
{
public:
    List();
    ~List();

    bool GetElem(int, int &);
    int ListLength();
    bool ListInsert(int, int);
    bool ListDelete(int, int &);

    int getLength() const;
    void setLength(int value);

private:
    int data[40];
    int length;

};

#endif // List_H
