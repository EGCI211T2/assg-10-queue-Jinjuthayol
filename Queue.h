#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
NodePtr headPtr,tailPtr;
int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
    bool isEmpty();
};

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



/*
void Queue::enqueue(int x){
  NodePtr new_node= new NODE(x);
if(new_node){
    //Add head and tail for me please
  1. connect & Change tail
  2. (may be) change head  when the queue is empty
  3. increase size

 }
}*/


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



/*int Queue::dequeue(){
  if(headPtr!=NULL){
     NodePtr t=headPtr;
     int value= t->get_value();
     //Add head and tail for me please
         
     delete t;
     return value;
  }
  cout<<"Empty queue";
  return -1;
}*/




Queue::Queue(){
    //initialize Queue
    headPtr = nullptr;
    tailPtr = nullptr;
    size = 0;
}

   
Queue::~Queue(){
    //delete all remaning Queue (i.e. DQ all)
    while (headPtr != nullptr) {
        dequeue(); // Remove all nodes
    }
}

bool Queue::isEmpty() {
    return headPtr == nullptr;
}

#endif
