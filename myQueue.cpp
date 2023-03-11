/* Assignment C++: 2
   Author: Ron Zilber
*/
#include "myQueue.h"

myQueue::myQueue(const int aMaxQ) :             /// Constructor (Default value is aMaxQ = 0)
    maxQ(aMaxQ), currentLength(0){               // Initialization list
    if(maxQ < 0) maxQ = 0;                       // Defends the object from negative input from user
    queueVector.resize(maxQ);            // Contains the element inside the queue
}
myQueue::~myQueue() {                          /// Destructor
    queueVector.clear();                        // Delete the vector that held the queue elements
}
int myQueue:: getCurrentLength()const{          /// Return the value of currentLength
    return (const int)currentLength;
}
bool myQueue::isEmpty() const {                  // Return True\False value: empty or not empty queue
    if(currentLength == 0) return true;
    return false;
}
bool myQueue::enQueue(const int num) {          /// Insert an element to the queue if there is space or return False otherwise
    if (currentLength == maxQ) {
        return false;                            // No place for new element because the queue is full
    } else {
        queueVector.push_back(num);              // Insert the element to the head of the queue
        currentLength++;                         // Update the queue length
        return true;
    }
}
bool myQueue::deQueue() {                       /// Remove the first element in the queue or return False if it is empty
    if (currentLength == 0) {
        return false;                                                    // The queue is empty
    } else {
        queueVector.erase( queueVector.begin() + currentLength ); // Delete the last element
        currentLength--;                                                 // Update the queue length
        return true;
    }
}
int myQueue::peek() {                    /// Return the first element in the queue or -1 if its empty
    if(currentLength == 0){
        return -1;                        // If the queue is empty return -1
    }
    return queueVector[maxQ];             // Return the first item in the queue (because it is filled from end to start)
}
ostream& operator<<(ostream& os, const myQueue & aQueue){ /// Print the queue in the form of x0 <- x1 <- ... <- xn
    if(aQueue.currentLength>0){                            // If the queue is empty, os will remain blank
        os << aQueue.queueVector[aQueue.maxQ];
        for (int i = 1; i < aQueue.currentLength; i++) {
            os << " <- " << aQueue.queueVector[aQueue.maxQ+  i] << "";
        }
    }
    return os;
}