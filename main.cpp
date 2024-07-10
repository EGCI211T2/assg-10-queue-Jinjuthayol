#include <iostream>
using namespace std;
#include "Queue.h"
#include <cstring>

int main(int argc , char **argv) {
  Queue q;
   int i,x;
   

 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
            x=q.dequeue();
            if(x!=-1) cout<<"dequeing "<<x<<endl;
        }
        else {
       q.enqueue(atoi(argv[i]));
           
        }
 }
  // Clear the remaining elements in the queue
    while (!q.isEmpty()) {
        int x = q.dequeue();
        if (x != -1) {
            std::cout << "dequeuing " << x << std::endl;
        }
    }
  return 0;
}
