#include <iostream>
#include <cstdlib> // For atoi function
#include <cstring>
#include "Queue.h"

using namespace std;

int main(int argc, char** argv) {
    Queue q;
    int i, x;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            x = q.dequeue();
            if (x != -1) {
                cout << "dequeuing " << x << endl;
            } else {
                cout << "Empty queue" << endl; // Print message for empty queue
            }
        } else {
            q.enqueue(atoi(argv[i]));
        }
    }

    // Clear the remaining elements in the queue
    while (!q.isEmpty()) {
        int x = q.dequeue();
        if (x != -1) {
            cout << "dequeuing " << x << endl;
        } else {
            cout << "Empty queue" << endl; // Print message for empty queue
        }
    }

    return 0;
}
