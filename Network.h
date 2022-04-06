#ifndef NETWORK_H
#define NETWORK_H
#include "Component.h"
#include <fstream>

class Network {
    private:
        static int networks;
        int index;
        int nNodes;
        Node* nodeArray;
    public:
        // constructor
        Network(int = 2);
        // destructor
        ~Network();
        // accessors
        const int getIndex();
        const int getNumNodes();
        const int getExistingNodes();
        // other member functions
        void setNodeVoltage(int, double);
        void reportNetworkInfo(std::ofstream&); 
        void connectComponent(Component*, int, int);
        Node* getNode(int);
};

#endif