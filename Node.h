#ifndef NODE_H
#define NODE_H
#include <fstream>

class Node {
    private:
        static int numNodes; 
        int index;
        double voltage;
    public:
        // constructors
        Node();
        // accessors
        const int getNumNodes();
        const int getNodeIndex();
        const double getNodeVoltage();
        // mutators
        void setNodeVoltage(double);
        // member functions
        const void writeNodeInfo(std::ofstream&);
};

#endif