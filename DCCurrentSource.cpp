#include "DCCurrentSource.h"
#include <fstream>
#include <cmath>
using namespace std;

// constructor
DCCurrentSource::DCCurrentSource() {
    current = 0;
}

// mutators and accessors
void DCCurrentSource::setCurrent(double i) {
    current = i;
}

const double DCCurrentSource::getCurrent() {
    return current;
}

const double DCCurrentSource::getPower() {
    return current * terminalVoltage();
}

// other member functions
void DCCurrentSource::reportInfo(ofstream &outfile) {
    outfile << "\nComponent # " << getIndex() << " is a DC Current Source, Is = " << current << " Amps.\n";
    
    // call component member function
    writeCompInfo(outfile);

    // report current and direction
    outfile << "The current in this DC Current Source = " << abs(current) << " Amps,\n";

    int fromNode, toNode;
    if (terminalVoltage() > 0) {
        fromNode = getANode();
        toNode = getBNode();
    }
    else {
        toNode = getANode();
        fromNode = getBNode();
    }
    outfile << "flowing from Node " << fromNode << " to Node " << toNode << ".\n";

    // report power supplied
    outfile << "The power supplied by this DC Current Source = " << getPower() << " Watts.\n";
}