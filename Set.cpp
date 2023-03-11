/* Assignment C++: 2
   Author: Ron Zilber
*/
#include "Set.h"

int Set:: setsCounter = 0;                           // This line initialize a static variable and will only happen once
/// ---------- Constructors & Destructor Section ---------------------------------------------------------------------//
Set::Set(const int aMaxSize):                        // Default & non-default constructor
    currentSize(0), maxSize(aMaxSize), serialNumber(setsCounter + 1) // Initialization list
    {
    arr = new int[maxSize];                                       // Create a new dynamic array to hold the set elements
    setsCounter += 1;                                             // Increase the class Set instances counter
 }
Set::Set(const Set &aSet):                           // Copy constructor
    serialNumber(setsCounter + 1), currentSize(aSet.currentSize), maxSize(aSet.maxSize){  // Initialization list
    setsCounter += 1;                                          // increase to static sets counter
    arr = new int[maxSize];                                    // This is important because we don't want a shallow copy
    for(int i = 0; i<maxSize;i++){                             // Copy the elements from the copied set to the new set
        arr[i] =  aSet.arr[i];
    }
}
Set::~Set(){                                         // Destructor
    delete[] arr;                                    // Free the dynamic allocated memory
    setsCounter -= 1;                                // Decrease the class Set instances counter
}
/// ---------- Friend Functions Section ------------------------------------------------------------------------------//
void swap(int & num1, int & num2){                  /// Swap the values of two integer variables
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void quickSort(int arr[], const int left, const int right){ // at first call left = 0 and right is size(arr) - 1
                                                       /// Sort an N elements array within a time complexity of O(NlogN)
    if(left < right - 1){                               // Stop condition
        int leftIndex = left, rightIndex = right - 1;
        int pivot = (left + right) / 2;
        swap(arr[pivot], arr[right]);
        while (leftIndex < rightIndex) {
            leftIndex = left, rightIndex = right - 1;
            while (leftIndex != right - 1) {
                if (arr[leftIndex] > arr[right]) {
                    break;
                }
                leftIndex++;
            }
            while (rightIndex != left - 1) {
                if (arr[rightIndex] < arr[right]) {
                    break;
                }
                rightIndex--;
            }
            if(leftIndex < rightIndex) {swap(arr[leftIndex], arr[rightIndex]);}
        }
        swap(arr[leftIndex], arr[right]);
        pivot = leftIndex;
        if(arr[right]<arr[right - 1]){
            swap(arr[right],arr[right-1]);
        }
        else if(arr[left]>arr[left + 1]){
            swap(arr[left],arr[left+1]);
        }
        quickSort(arr, pivot + 1   , right ); // Recursive call for the right side
        quickSort(arr, left , pivot  );      // Recursive call for the left side
    }
    else if(left == right -1){                    // Sort the last recursion level - with 2 elements arrays
        if(arr[left] > arr[right]){
            swap(arr[left],arr[right]);
        }
    }
}
int binarySearch(const int num, const int arr[], const int size){
    /// Find the index of element in a sorted N elements array within time complexity of O(NlogN)
    if(size > 1) {                   // Else, there is only one element at index 0, will be checked below
        int left = 0, right = size - 1, middle = (left + right) / 2;
        if (arr[left] == num) {
            return left;             // The element has been found - return its index
        } else if (arr[right] == num) {
            return right;            // The element has been found - return its index
        }
        while (right - left > 1) {
            if (arr[middle] == num) {
                return middle;       // The element has been found - return its index
            } else if (arr[middle] > num) {
                right = middle;
                middle = (left + right) / 2;
            } else if (arr[middle] < num) {
                left = middle;
                middle = (left + right) / 2;
            }
        }
    }
    else if (arr[0] == num){
        return 0; // The index of the desired number is actually 0
    }
    return -1;    // The desired number is not in the given array
}
/// ---------- Getters Section ---------------------------------------------------------------------------------------//
int Set:: getCurrentSize() const{                                 // Return the value of currentSize
    return currentSize;
}
int Set:: getMaxSize() const{                                     // Return the value of maxSize
    return maxSize;
}
int Set::getSerialNumber() const {                                // Return the value of serialNumber
    return serialNumber;
}
/// ---------- Dynamic Memory Section --------------------------------------------------------------------------------//
void Set::reAlloc() { /// If the set is full, we reallocate the array to a double sized dynamic array
    if(currentSize == maxSize){                   // Check if there is not enough room for a new element
        int * temp_ptr = arr;                     // New temporal pointer to the dynamic array
        arr = new int[2 * maxSize];               // Point arr to the new double sized dynamic array
        for(int i = 0; i < maxSize; i ++){        // Copy the elements to the new dynamic array
            arr[i] = temp_ptr[i];
        }
        delete[] temp_ptr;                        // Delete the old dynamic array (free the memory)
        maxSize = 2 * maxSize;                    // Update the maxSize field of the object to 2 * maxSize
        }
 }
void Set::reAlloc(const int newSize) {           /// Used only in '=' operator when the new size is specified
    int * temp_ptr = arr;                         // New temporal pointer to the dynamic array
    arr = new int[newSize];                       // Point arr to the new sized dynamic array
    delete[] temp_ptr;                            // Delete the old dynamic array (free the memory)
    maxSize = newSize;                            // Update the maxSize field of the object to newSize
}
/// ---------- Operators Section -------------------------------------------------------------------------------------//
Set& Set::operator +(const int num){ /// Add an integer to the operating set
    *this += num;
    return *this;
}
Set operator +(const int num, const Set & otherSet){ /// Create a set and add the operating integer to it
    Set set =  otherSet;                              // Create a set to add the given number to
    set += num;                                       // Add the number to the set
    return set;
}
Set Set::operator+(const Set & otherSet) const{      /// Unite two sets and return the union as a new set
    Set unionSet = *this;                             // First - copy the operating object to a new object
    for(int i = 0; i< otherSet.currentSize; i++){     // Add the numbers from the other set to the return set
        unionSet += otherSet.arr[i];
    }
    return unionSet;
}
void Set:: operator+=(const int num){           /// Add an integer to the operating Set object
    int isThere = binarySearch(num,arr, currentSize);
    if (isThere == -1) {                         // binarySearch returns index of item or -1 if it is not found
        reAlloc();                               // If the set is full - reallocation to bigger dynamic array will occur
        arr[currentSize] = num;                  // Add the number to the end of the elements area at the dynamic array
        quickSort(arr, 0, currentSize); // Sort again the array that holds the set element after the addition
        currentSize++;                           // Increase the currentSize field because an element has been added
    }
}
ostream& operator<<(ostream& os, const Set& set){ /// Print the set in the form of {x1,x3,,,,.xn} to the user
    int size = set.currentSize;                    // Just take a shorter name for readability
    if(size>0) {                                   // Else, os will remain empty
        os << "{";
        for (int i = 0; i < size - 1; i++) {
            os << set.arr[i] << ",";
        }
        os << set.arr[size - 1];
        os << "}";
    }
    return os;
}
Set& Set:: operator =(const Set & otherSet) {   /// Deep copy the argument set the operating set
    if(this != &otherSet) {                      // Prevent self-assembly situation
        cout << "old set size before: " << this->maxSize << endl;
        if(this->maxSize<otherSet.maxSize){      // Promise there is enough space to place elements in the dynamic array
            this->reAlloc(otherSet.maxSize);
        }
        this->currentSize = otherSet.currentSize;
        this->maxSize = otherSet.maxSize;
        for (int i = 0; i < currentSize; i++) {  // Copy the elements from the argument set to the operating set
            this->arr[i] = otherSet.arr[i];
        }
    }
    return *this;
}
const int& Set:: operator [](int num)const{ /// Return an element in the set by a given index
    return this->arr[num];
}
bool Set:: operator >(Set & otherSet)const{ /// Return True/False value by comparing two sets lengths
    if(currentSize > otherSet.currentSize){
        return true;
    }
    return false;
}
bool Set:: operator <(Set & otherSet)const{ /// Return True/False value by comparing two sets lengths
    if(currentSize < otherSet.currentSize){
        return true;
    }
    return false;
}
/// ------------------------------------------------------------------------------------------------------------------//