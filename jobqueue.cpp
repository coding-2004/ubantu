#include <iostream>
using namespace std;

const int MAX = 3; // Maximum size of the queue

class JobQueue {
    int jobs[MAX];
    int front, rear;

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void addJob(int job) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more jobs." << endl;
        } else {
            if (front == -1)
                { front = 0;}
                // front =rear=0; 
            rear++;              
            jobs[rear] = job;
           // rear++;
            cout << "Job " << job << " added to queue." << endl;
        }
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue is empty. No jobs to delete." << endl;
        } else {
            cout << "Job " << jobs[front] << " deleted from queue." << endl;
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Jobs in queue: ";
            for (int i = front; i <= rear; i++) {
                cout << jobs[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    JobQueue q;
    q.addJob(101);
    q.addJob(102);
    q.addJob(103);
    q.addJob(13);
    q.displayQueue();
    q.deleteJob();
    q.displayQueue();
    return 0;
}
