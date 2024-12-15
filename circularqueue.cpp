#include <iostream>
#define MAX 5  // Define the maximum size of the queue

using namespace std;

class Queue
{
private:int
    int a[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % MAX;
            a[rear] = value;
            cout << value << " enqueued to queue\n";
        }
    }

     dequeue()
    {
        int value;
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        else
        {
            value = a[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
            return value;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty queue\n";
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = front; i != rear; i = (i + 1) % MAX)
            {
                cout << a[i] << " ";
            }
            cout << a[rear] << "\n";
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    

    q.display();

    cout << "Dequeued: " << q.dequeue() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
