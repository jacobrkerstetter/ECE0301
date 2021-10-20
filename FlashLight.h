#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

class FlashLight {
    // declare private attributes
    private:
        double voltage;
        double resistance;
        bool switchState;
    
    // declare public constructor and other member functions
    public:
        FlashLight();
        void setVoltage(double);
        void setResistance(double);
        void setSwitchState(bool);
        double getVoltage();
        double getResistance();
        bool getSwitchState();
        double getCurrent();
        double getPower();
        void printData();
}; // end FlashLight

#endif