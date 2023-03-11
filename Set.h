/* Assignment C++: 2
   Author: Ron Zilber
*/
#ifndef __SET_H
#define __SET_H
#include <iostream>
using namespace std;

class Set{                                               /// Hold a mathematical set of numbers (i.e, sorted and without repetitions)
private:
    static int setsCounter;                               // Count the instances of class Set objects
    int maxSize;                                          // Maximal number of elements
    int currentSize;                                      // Current number of elements
    int * arr;                                            // an Array that will hold the elements of the set
    int serialNumber;                                     // The serial number of the object
    void reAlloc();
    void reAlloc(int);
public:
    explicit Set(int aMaxSize = 1000);                    // Default constructor
    Set(const Set &);                                     // Copy constructor
    ~Set();                                               // Destructor
    int getCurrentSize() const;                           // Return the value of currentSize
    int getMaxSize() const;                               // Return the value of maxSize
    int getSerialNumber()const;                           // Return the value of serialNumber
    friend int binarySearch(int, const int *, int);       // Find the index of element in a sorted N elements array within time complexity of O(NlogN)
    friend void quickSort(int *, int, int);               // Sort an N elements array within a time complexity of O(NlogN)
    void operator +=(int);                                // Add a number to the set
    Set operator +(const Set &)const;                     // Create a union of two sets
    Set& operator +(int);                                 // Add a number to the set
    friend Set operator +(int, const Set&);               // Add the number to a given set
    const int& operator[](int ) const;                    // Return an element in the set by a given index
    bool operator >(Set &)const;                          // Return True/False value by comparing two sets lengths
    bool operator <(Set &)const;                          // Return True/False value by comparing two sets lengths
    Set& operator =(const Set &);                         // Deep copy the argument set the operating set
    friend ostream& operator<<(ostream& os, const Set& ); // Print the set in the form of {x1,x3,,,,.xn} to the user
};
void swap(int & num1, int & num2);                        // Swap the values of two integer variables
int binarySearch(int, const int *, int);                  // Search for a number in a sorted N elements array within a time complexity of O(NlogN)
void quickSort(int *, int, int);                          // Sort an N elements array within a time complexity of O(NlogN)
#endif // __SET_H