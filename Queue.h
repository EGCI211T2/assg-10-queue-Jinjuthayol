#ifndef queue_h
#define queue_h
using namespace std;
#include "Node.h"

class Queue {
private:
    NodePtr headPtr;
    NodePtr tailPtr;
    int size;

public:
    Queue();
    ~Queue();

    void enqueue(int);
    int dequeue();
    bool isEmpty();
};

Queue::Queue() {
    headPtr = nullptr;
    tailPtr = nullptr;
    size = 0;
}

Queue::~Queue() {
    while (headPtr != nullptr) {
        dequeue(); // Remove all nodes
    }
}

void Queue::enqueue(int x) {
    NodePtr new_node = new NODE(x); // Create a new node with value x

    if (new_node) {
        if (tailPtr == nullptr) {
            // If queue is empty, new node becomes both head and tail
            headPtr = new_node;
            tailPtr = new_node;
        } else {
            // Add new node after current tail
            tailPtr->set_next(new_node);
            tailPtr = new_node;
        }
        size++; // Increase the size of the queue
    }
}

int Queue::dequeue() {
    if (headPtr != nullptr) {
        NodePtr t = headPtr;
        int value = t->get_value(); // Get the value of the node
        headPtr = headPtr->get_next(); // Move head to next node
        delete t; // Delete the node
        size--; // Decrease the size of the queue

        if (headPtr == nullptr) {
            tailPtr = nullptr; // If queue is empty, reset tail pointer
        }

        return value;
    }

    cout << "Empty queue" << endl;
    return -1;
}

bool Queue::isEmpty() {
    return headPtr == nullptr;
}

#endif
