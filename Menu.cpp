/* Assignment C++: 2
   Author: Ron Zilber
*/
#include "Menu.h"

Menu::Menu(int num) : mainState(0), setState(0), queueState(0){} // Default Constructor
void Menu::mainMenu() {                         /// Final State Machine for the main menu
    bool flag = false;
    while(!flag){                                // The flag get 'true' value when the user want to go out from this menu
        cout << "(1) Set Menu\n"
                "(2) Integer Queue Menu\n"
                "(3) Exit\n";
        cin >> mainState;                        // Get the desired option from the user
        switch (mainState) {
            case 1:{
                Set set1; Set set2;              // Creates set1 & set2  (class Set objects)
                setMenu(set1, set2);      // Go to the Set Final State Machine
                break;
            }
            case 2:{
                int queueNum;
                cout << "Enter the size of the queue: ";
                cin >> queueNum;               // Get the desired option from the user
                if(queueNum < 0) queueNum = 0; // Only positive queue size is available
                myQueue queue(queueNum);// Create a queue with non-negative length
                queueMenu(queue);           // Go to the queue Final State Machine
                break;
            }
            case 3:{
                cout << "Goodbye!";
                flag = true;                   // Go out of the loop and end the program
                break;
            }
            default:{
                cout << "Invalid selection." << endl;
                break;
            }
        }
    }
}
Menu::~Menu() = default;
void Menu::setMenu(Set & aSet1, Set & aSet2) { /// Final State Machine for shop menu
    bool flag = false;                          // The flag get 'true' value when the user want to go out from this menu
    while(!flag){
        cout <<"*** Welcome to Set Menu ***\n"
                "To select an item, enter\n"
                "1 Show set 1\n"
                "2 Show set 2\n"
                "3 add element to set 1\n"
                "4 add element tp set 2\n"
                "5 Show set1 U set 2 (union)\n"
                "6 to exit\n";
        cin >> setState;                        // Get the desired option from the user
        switch (setState) {
            case 1:{
                if(!aSet1.getCurrentSize()){
                    cout << "Set " << aSet1.getSerialNumber() << " is empty" << endl;
                }
                else cout << aSet1 << endl;
                break;
            }
            case 2:{
                if(!aSet2.getCurrentSize()){
                    cout << "Set " << aSet2.getSerialNumber() << " is empty" << endl;
                }
                else cout << aSet2 << endl;
                break;
            }
            case 3:{
                int num;
                cout << "Give a number:" <<" ";
                cin >> num;                    // Get the desired number from the user
                aSet1 += num;                  // Add the desired number to the set
                break;
            }
            case 4:{
                int num;
                cout << "Give a number:" << " ";
                cin >> num;                    // Get the desired number from the user
                aSet2 += num;                  // Add the desired number to the set
                break;
            }
            case 5:{
                Set u = aSet1 + aSet2;         // Create a united set out of set1 and set2
                if(!u.getCurrentSize()) cout <<"The union is empty" << endl; // i.e, the union is empty
                else cout << u << endl;        // Print the united set to the user
                break;
            }
            case 6:{
                flag = true; // Exit to main menu
                break;
            }
            default:{
                cout << "Invalid selection." << endl; // For input that are not in the menu
                break;
            }
        }
    }
}
void Menu::queueMenu(myQueue & aQueue){
    bool flag = false;           // The flag get 'true' value when the user want to go out from this menu
    while(!flag){
        cout << "*** Welcome to Queue Menu ***\n"
                "To select an item, enter\n"
                "1 Show Queue\n"
                "2 Insert new element\n"
                "3 Remove element\n"
                "4 Check the first element\n"
                "5 to exit\n";
        cin >> queueState;
        switch (queueState) {               // Final State Machine for queue menu
            case 1:{
                if(aQueue.getCurrentLength() == 0){
                    cout << "The queue is empty" << endl;
                }
                else cout << aQueue << endl;
                break;
            }
            case 2:{
                int num;
                cout << "insert new element: ";
                cin >> num;
                if(aQueue.enQueue(num)){
                    cout <<"The new queue:" << endl;
                    cout << aQueue << endl;
                }
                else{
                    cout << "Queue is full"<< endl;
                }
                break;
            }
            case 3:{
                if(aQueue.deQueue()){
                    if(aQueue.getCurrentLength() == 0){
                        cout << "Queue is empty" << endl;
                    }
                    else {
                        cout << "The new queue:" << endl;
                        cout << aQueue << endl;
                    }
                }
                else{
                    cout << "Queue is empty"<< endl;
                }
                break;
            }
            case 4:{
                if(!aQueue.getCurrentLength()){ // the returned value is 0 only for empty queue
                    cout << "Queue is empty"<< endl;
                }
                else cout << aQueue.peek() << endl;
                break;
            }
            case 5:{
                flag = true;
                break;
            }
            default:{
                cout << "Invalid selection." << endl;
                break;
            }
        }
    }
}