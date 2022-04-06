#ifndef RESISTOR_H
#define RESISTOR_H
#include "Component.h"

class Resistor : public Component {
    private:
        double resistance;
    public:
        // constructor
        Resistor();
        // accessor and mutator
        const double getResistance();
        void setResistance(double R);
        // other member functions
        void reportResistorInfo(std::ofstream&);
        const double getCurrent();
        const double getPower();
};  

#endif