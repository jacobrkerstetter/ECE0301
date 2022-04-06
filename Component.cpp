#include "Component.h"
#include <fstream>
#include <cmath>
using namespace std;

int Component::numComponents = 0;

Component::Component() {
    // set index
    index = numComponents;

    // increment number of components
    numComponents++;

    // initialize terminal ptrs
    terminalA = nullptr;
    terminalB = nullptr;
}

// accessors and mutators
const int Component::getNumComponents() { return numComponents; }
const int Component::getIndex() { return index; }
void Component::setTerminalA(Node* node) { terminalA = node; }
void Component::setTerminalB(Node* node) { terminalB = node; }
const int Component::getANode() { return terminalA->getNodeIndex(); };
const int Component::getBNode() { return terminalB->getNodeIndex(); };

// other member functions
void Component::writeCompInfo(ofstream &outfile) {
    Node *negTerminal = (terminalA->getNodeVoltage() < terminalB->getNodeVoltage()) ? terminalA : terminalB;
    outfile << "Component # " << index << " is connected between node " << getANode() << " and node " << getBNode() << "." << endl;
    outfile << "The Voltage across Component # " << index << " = " << abs(terminalVoltage()) << " Volts,\n";
    outfile << "with the negative terminal at node " << negTerminal->getNodeIndex() << ".\n";
}

double Component::terminalVoltage() {
    return terminalB->getNodeVoltage() - terminalA->getNodeVoltage();
}