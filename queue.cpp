#include "queue.h"

Queue::Queue()
{

}

Queue::Queue(int maxsize){
    this->MAX_SIZE = maxsize;
    data = new int[static_cast<unsigned long long>(MAX_SIZE)];
}

bool Queue::InitQueue(){
    this->front = 0;
    this->rear = 0;
    return true;
}

int Queue::QueueLength(){
    return (rear-front+MAX_SIZE)%MAX_SIZE;
}

bool Queue::EnQueue(const int e){
    if((rear+1)%MAX_SIZE == front)
        return false;
    data[rear] = e;
    rear = (rear+1)%MAX_SIZE;
    return true;
}

bool Queue::DeQueue(int &e){
    if(front == rear)
        return false;
    e = data[front];
    front = (front+1)%MAX_SIZE;

    return true;
}

