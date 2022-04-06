#include "Node.h"
#include <fstream>
#include <iostream>
using namespace std;

// define static member
int Node::numNodes = 0;

// define default constructor
Node::Node() {
    // assign the correct index to the node
    index = numNodes;

    // increment numNodes
    numNodes++;

    // set voltage to 0
    voltage = 0;
}

// accessors
const int Node::getNodeIndex() { return index; }
const int Node::getNumNodes() { return numNodes; }
const double Node::getNodeVoltage() { return voltage; }

// mutators
void Node::setNodeVoltage(double v) { voltage = v; }

// member functions
const void Node::writeNodeInfo(ofstream &outfile) {
    outfile << "Voltage at node " << this->index << " = " << this->voltage << "." << endl;
}