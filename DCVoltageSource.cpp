#include "DCVoltageSource.h"
#include <fstream>
using namespace std;

// constructor
DCVoltageSource::DCVoltageSource() {
    voltage = 0;
}

// accessor and mutator
void DCVoltageSource::setVoltage(double v) {
    voltage = v;
}
void DCVoltageSource::setCurrent(double i) {
    current = i;
}

const double DCVoltageSource::getVoltage() {
    return voltage;
}
const double DCVoltageSource::getCurrent() {
    return current;
}

// member function writeSourceInfo
void DCVoltageSource::writeSourceInfo(ofstream &outfile) {
    // write DC source info
    outfile << "\nComponent # " << getIndex() << " is a DC Voltage Source, Vs = " << voltage << " Volts.\n";

    // call component function
    writeCompInfo(outfile);

    // report current and direction
    int fromNode, toNode;
    if (terminalVoltage() > 0) {
        fromNode = getANode();
        toNode = getBNode();
    }
    else {
        fromNode = getBNode();
        toNode = getANode();
    }

    outfile << "The current in this DC Voltage Source = " << abs(getCurrent()) << " Amps,\n";
    outfile << "flowing from Node " << fromNode << " to Node " << toNode << ".\n";

    // report power supplied
    outfile << "The power supplied by this DC Voltage Source = " << getPower() << " Watts.\n";
}

double DCVoltageSource::getPower() {
    return voltage * current;
}