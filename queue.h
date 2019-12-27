#ifndef QUEUE_H
#define QUEUE_H



class Queue
{
public:
    Queue();
    Queue(int);
    Queue(Queue *);
    ~Queue();

    bool InitQueue();
    int QueueLength();
    bool EnQueue(const int );
    bool DeQueue(int &);

private:
    int front;
    int rear;
    int *data;
    int MAX_SIZE;

};

#endif // QUEUE_H
