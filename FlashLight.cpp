#include "FlashLight.h"
#include <cmath>
#include <iostream>
using namespace std;

FlashLight::FlashLight() {
    voltage = 3.0;
    resistance = 100;
    switchState = false;
}
void FlashLight::setVoltage(double V) { voltage = V; }
void FlashLight::setResistance(double R) { resistance = R; }
void FlashLight::setSwitchState(bool S) { switchState = S; }
double FlashLight::getVoltage() { return voltage; }
double FlashLight::getResistance() { return resistance; }
bool FlashLight::getSwitchState() { return switchState; }
double FlashLight::getCurrent() { return voltage/resistance; }
double FlashLight::getPower() { return pow(voltage, 2)/resistance; }
void FlashLight::printData() {
    cout << "Here are the data on the FlashLight:" << endl;
    cout << "The battery voltage is " << voltage << " Volts." << endl;
    cout << "The bulb resistance is " << resistance << " Ohms." << endl;

    // determine if switch is opened or closed and if the flashlight is on or off
    if (switchState == true) {
        cout << "The FlashLight is on." << endl;
        cout << "The switch is open" << endl;
    }
    else {
        cout << "The switch is closed" << endl;
        cout << "The FlashLight is off" << endl;
    }

    cout << "The bulb current is " << getCurrent() << " Amperes." << endl;
    cout << "The bulb power is " << getPower() << " Watts." << endl;
}