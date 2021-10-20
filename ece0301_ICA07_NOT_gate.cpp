#include <iostream>
#include <cmath>
using namespace std;

// class definition for NOTGate
class NOTGate {
    
    // declare private members
    private:
        string label;
        bool logicVal;

    // declare public functions and write them
    public:
        void setLabel(string s) { label = s; }
        void setLogicVal(bool b) { logicVal = b; }
        string getLabel() { return label; }
        bool getLogicVal() { return logicVal; }
        string getOutputLabel() { return label + "_not"; }
        bool getOutputLogic() { return !logicVal; }
}; // end NOTGate

int main() {
    
    // display intro message
    cout << "This program will simulate a note gate." << endl;
    cout << "What is the label for the gate input? ";

    // read in the user input into a string and put it into a not gate object
    NOTGate userGate;

    string userLabel;
    cin >> userLabel;
    cin.ignore();

    userGate.setLabel(userLabel);

    // prompt for logic value (0/1)
    cout << "What is the logic value at the input (0/1)? ";

    // read the user input and put into not gate object
    bool userLogic;
    cin >> userLogic;

    userGate.setLogicVal(userLogic);

    // output the data to the screen
    cout << "Here are the data on the not gate:" << endl;
    cout << "Input label: " << userGate.getLabel() << endl;
    cout << "Output labe: " << userGate.getOutputLabel() << endl;
    cout << "Logic value at input: " << userGate.getLogicVal() << endl;
    cout << "Logic value at output: " << userGate.getOutputLogic() << endl;
 
    return 0;
} // end main