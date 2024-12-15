#include <iostream>
#define M 5  // Maximum number of orders

using namespace std;

class CircularQueue {
private:
    int orders[M];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == M - 1) || (front== rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Cannot place order " << orderID << ": Order queue is full\n";
        } else {
            if (front == -1) { // First order
                front = rear = 0;
            } else if (rear == M - 1 && front != 0) {
                rear = 0;
            } else {
                rear++;
            }
            orders[rear] = orderID;
            cout << "Order " << orderID << " placed successfully\n";
        }
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "Order queue is empty: No orders to serve\n";
        } else {
            cout << "Serving order " << orders[front] << "\n";
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % M;
            }
        }
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "Order queue is empty\n";
        } else {
            cout << "Orders in queue: ";
            for (int i = front; i != rear; i = (i + 1) % M) {
                cout << orders[i] << " ";
            }
            cout << orders[rear] << "\n";
        }
    }
};

int main() {
    CircularQueue queue;
    queue.placeOrder(101);
    queue.placeOrder(102);
    queue.placeOrder(103);
    queue.placeOrder(104);
    queue.placeOrder(105);

    queue.displayOrders();

    queue.serveOrder();
    queue.serveOrder();

    queue.displayOrders();

    queue.placeOrder(106);
    queue.placeOrder(107);

    queue.displayOrders();

    return 0;
}
