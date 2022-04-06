#include "VoltageDivider.cpp"
#include "Network.cpp"
#include "Component.cpp"
#include "Resistor.cpp"
#include "DCVoltageSource.cpp"
#include "Node.cpp"
#include "DCCurrentSource.cpp"
#include "CurrentDivider.cpp"
#include <fstream>
#include <string>
using namespace std;

int main() {
    // define an ifstream object
    ifstream infile("ECE 0301 - Circuits to Simulate.txt");

    // define an ofstream object
    ofstream outfile("ECE 0301 - Electrical Network Reports.txt");

    // output header
    outfile << "ECE 0301 - Electrical Network Simulation\n";

    // define variable for file read
    double Vs, Is, R1, R2;
    string fileType;
    
    // loop through and read for each type of circuit
    while (getline(infile, fileType)) {

        // error case
        if (fileType != string("Voltage Divider") && fileType != string("Current Divider")) {
            cout << "ERROR! Invalid network type.";
            exit(EXIT_FAILURE);
        }
        // voltage divider case
        else if (fileType == "Voltage Divider") {
            // read values in
            infile >> Vs >> R1 >> R2;

            // define voltage divider object and call write info function
            VoltageDivider vd(Vs, R1, R2);
            vd.reportInfo(outfile);
        }
        // current divider case
        else {
            // read values in
            infile >> Is >> R1 >> R2;

            // define current divider object and call write info function
            CurrentDivider cd(Is, R1, R2);
            cd.reportInfo(outfile);
        }
        infile.ignore();
    }

    // close files
    infile.close();
    outfile.close();

    return 0;
}