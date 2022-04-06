#include "Resistor.h"
#include <fstream>
#include <cmath>

// constructor
Resistor::Resistor() {
    resistance = 1000;
}

// accessor and mutator
const double Resistor::getResistance() {
    return resistance;
}

void Resistor::setResistance(double R) {
    resistance = R;
}

// other member functions
void Resistor::reportResistorInfo(ofstream &outfile) {
    // write resistor info
    outfile << "\nComponent # " << getIndex() << " is a Resistor, R = " << resistance << " Ohms.\n";

    // call component writing function
    writeCompInfo(outfile);

    int fromNode, toNode;
    if (terminalVoltage() > 0) {
        fromNode = getBNode();
        toNode = getANode();
    }
    else {
        fromNode = getANode();
        toNode = getBNode();
    }

    // report current and direction
    outfile << "The current in this Resistor = " << abs(getCurrent()) << " Amps,\n";
    outfile << "flowing from Node " << fromNode << " to Node " << toNode << ".\n";

    // report power dissipated
    outfile << "The power dissipated in this Resistor = " << getPower() << " Watts.\n";
}

const double Resistor::getCurrent() {
    return terminalVoltage() / resistance;
}

const double Resistor::getPower() {
    return pow(getCurrent(), 2) * resistance;
}