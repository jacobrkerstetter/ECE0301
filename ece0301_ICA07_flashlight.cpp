#include <iostream>
#include "FlashLight.cpp"
using namespace std;

int main() {

    // declare an instance of FlashLight using constructor
    FlashLight flashlight = FlashLight();

    // call the member function to display info
    flashlight.printData();

    // loop to give user options
    int choice = 0;

    do {
        // print menu
        cout << "\nWhat would you like to do with the FlashLight?\n";
        cout << "(1) Change the battery voltage" << endl;
        cout << "(2) Change the bulb resistance" << endl;
        cout << "(3) Toggle the switch state" << endl;
        cout << "(4) Exit the program" << endl;
        cout << "Your selection? ";

        // get user choice
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                // prompt for voltage and set it to the flashlight
                double userVolts;
                cout << "\n\nEnter the new battery voltage: ";
                cin >> userVolts;

                flashlight.setVoltage(userVolts);
                flashlight.printData();
                break;
            case 2:
                // prompt for resistance and set it to the flashlight
                double userRes;
                cout << "\n\nEnter the new bulb resistance: ";
                cin >> userRes;

                flashlight.setResistance(userRes);
                flashlight.printData();
                break;
            case 3:
                // toggle the switch state
                flashlight.setSwitchState(!flashlight.getSwitchState());
                flashlight.printData();
                break;
            case 4:
                // exit the loop
                break;
        }
    } while (choice != 4);

    return 0;
} // end main