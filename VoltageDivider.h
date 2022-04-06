#ifndef VOLTAGEDIVIDER_H
#define VOLTAGEDIVIDER_H
#include "Network.h"
#include "DCVoltageSource.h"
#include "Resistor.h"

class VoltageDivider : public Network {
    private:
        DCVoltageSource Vs;
        Resistor R1;
        Resistor R2;
    public:
        // constructors
        VoltageDivider();
        VoltageDivider(double, double, double);
        // mutators
        void setVoltage(double);
        void setResistance(double, double);
        // other member functions
        void reportInfo(std::ofstream&);
        void calcValues();
};

#endif 