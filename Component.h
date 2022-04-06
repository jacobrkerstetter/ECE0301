#ifndef COMPONENT_H
#define COMPONENT_H
#include "Node.h"
#include <fstream>

class Component {
    private:
        static int numComponents;
        int index;
        Node* terminalA;
        Node* terminalB;
    public:
        // constructor
        Component();
        // accessors and mutators
        const int getNumComponents();
        const int getIndex();
        void setTerminalA(Node*);
        void setTerminalB(Node*);
        const int getANode();
        const int getBNode();
        // other member functions
        void writeCompInfo(std::ofstream&);
        double terminalVoltage();
};

#endif