
class Queue
{

    int *arr;
    int cs;
    int ms;

    int front;
    int rear;

public:
    Queue(int default_size = 5)
    {
        ms = default_size;
        arr = new int[ms];
        cs = 0;
        front = 0;
        rear = ms - 1;
    }

    bool full()
    {
        return cs == ms;
    }

    bool empty()
    {
        return cs == 0;
    }

    void push(int data)
    {

        if (!full())
        {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }

    void pop()
    {
        // we can only pop if wueue is not empty
        if (!empty())
        {
            // tae the front pointer forward
            front = (front + 1) % ms;
            // reduce the current size
            cs--;
        }
    }

    int get_front()
    {
        return arr[front];
    }
};