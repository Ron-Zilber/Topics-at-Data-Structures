/* Assignment C++: 2
   Author: Ron Zilber
*/
#ifndef __MYQUEUE_H
#define __MYQUEUE_H
#include <iostream>
#include <vector>
using namespace std;
class myQueue{                       // Operate a queue of integers (FIFO Policy)
private:
    int maxQ;                        // The capacity of the queue
    vector<int> queueVector;         // Contains the element inside the queue
    int currentLength;               // The current length of the queue
public:
    explicit myQueue(int aMaxQ = 0); // The default constructor
~myQueue();                          // The default destructor
    int getCurrentLength() const;    // Return the current queue length
    bool enQueue(int val);           // Insert a new element at the end of the queue. Return true if succeed and false otherwise
    bool deQueue();                  // Remove the next element in the queue. Return true if succeed and false otherwise
    bool isEmpty() const;            // Return true if the queue is empty and false otherwise
    int peek();                      // Return the first element of the queue or -1 if its empty
    friend ostream& operator<<(ostream&, const myQueue &); // Print the queue in the form of x0 <- x1 <- ... <- xn
};
#endif //__MYQUEUE_H