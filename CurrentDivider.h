#ifndef CURRENTDIVIDER_H
#define CURRENTDIVIDER_H
#include "Network.h"
#include "DCCurrentSource.h"
#include "Resistor.h"
#include <fstream>

class CurrentDivider : public Network {
    private:
        DCCurrentSource Is;
        Resistor R1;
        Resistor R2;
    public:
        // constructors
        CurrentDivider();
        CurrentDivider(double, double, double);
        // mutators
        void setIs(double);
        void setRs(double, double);
        // other member functions
        void calcValues();
        void reportInfo(std::ofstream&);
};

#endif