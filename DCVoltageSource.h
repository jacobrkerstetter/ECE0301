#ifndef DCVOLTAGESOURCE_H
#define DCVOLTAGESOURCE_H
#include "Component.h"

class DCVoltageSource : public Component {
    private:
        double voltage;
        double current;
    public:
        // constructor
        DCVoltageSource();
        // accessor and mutator
        void setVoltage(double v);
        void setCurrent(double i);
        const double getVoltage();
        const double getCurrent();
        // other member functions
        void writeSourceInfo(std::ofstream&);
        double getPower();
};

#endif