/* Assignment C++: 2
   Author: Ron Zilber
*/
#include "myQueue.h"
#include "Set.h"
class Menu{                              // Operate as a user interface
private:
    int mainState, setState, queueState; // Initializing some auxiliary variables for Final State Machines

public:
    explicit Menu(int num=0);            // The default constructor
    void mainMenu();                     // User interface built as a Final State Machine
    void setMenu(Set &, Set &);          // User interface built as a Final State Machine
    void queueMenu(myQueue &);           // User interface built as a Final State Machine
    ~Menu();                             // Destructor
};