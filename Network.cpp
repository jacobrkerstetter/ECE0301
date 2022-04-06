#include <fstream>
#include "Network.h"
using namespace std;

// static number of networks
int Network::networks = 0;

// constructor
Network::Network(int n) {
    // assign index
    index = networks;

    // increment number of networks
    networks++;

    // set number of nodes
    nNodes = n;

    // allocate memory for array
    nodeArray = new Node[n];
}

// destructor
Network::~Network() {
    delete [] nodeArray;
}

// accessors
const int Network::getIndex() { return index; }
const int Network::getNumNodes() { return nNodes; }
const int Network::getExistingNodes() { return nodeArray[0].getNumNodes(); }

// other member functions
void Network::setNodeVoltage(int index, double v) { nodeArray[index].setNodeVoltage(v); }

void Network::reportNetworkInfo(ofstream &outfile) {
    outfile << "At present, there are " << networks << " Networks in existence." << endl;
    outfile << "At present, there are " << getExistingNodes() << " nodes in existence." << endl;
    outfile << "Network # " << index << " contains " << nNodes << " nodes." << endl;
    for (int i = 0; i < nNodes; i++)
        nodeArray[i].writeNodeInfo(outfile);
    }

// connection components function
void Network::connectComponent(Component *component, int idxA, int idxB) {
    // set terminalA node pointer
    component->setTerminalA(getNode(idxA));

    // set terminalB node pointer
    component->setTerminalB(getNode(idxB));
}

// return node pointer function
Node* Network::getNode(int idx) {
    return &nodeArray[idx];
}