#include "VoltageDivider.h"
#include <fstream>
using namespace std;

VoltageDivider::VoltageDivider() : Network(3) { 
    // set Vs and Resistors
    Vs.setVoltage(1);
    R1.setResistance(1000);
    R2.setResistance(1000);

    // connect components
    connectComponent(&Vs, 0, 1);
    connectComponent(&R1, 1, 2);
    connectComponent(&R2, 2, 0);

    // call calculate values function
    calcValues();
}

VoltageDivider::VoltageDivider(double v, double Res1, double Res2) : Network(3) {
    // set Vs and Resistors
    Vs.setVoltage(v);
    R1.setResistance(Res1);
    R2.setResistance(Res2);

    // connect components
    connectComponent(&Vs, 0, 1);
    connectComponent(&R1, 1, 2);
    connectComponent(&R2, 2, 0);

    // call calculate values function
    calcValues();
}

// mutators
void VoltageDivider::setVoltage(double v) {
    Vs.setVoltage(v);

    // call calculate values function
    calcValues();
}

void VoltageDivider::setResistance(double Res1, double Res2) {
    R1.setResistance(Res1);
    R2.setResistance(Res2);

    // call calculate values function
    calcValues();
}

// report info function
void VoltageDivider::reportInfo(ofstream &outfile) {
    outfile << endl;

    for (int i = 0; i < 48; i++)
        outfile << "-";
    outfile << "\n\nData for Electric Network # " << getIndex() << ":\n";
    outfile << "Network # " << getIndex() << " is a Voltage Divider.\n";
    
    // call report info function
    reportNetworkInfo(outfile);

    // write about components
    outfile << "At present, there are " << Vs.getNumComponents() << " components in existence.\n";

    Vs.writeSourceInfo(outfile);
    R1.reportResistorInfo(outfile);
    R2.reportResistorInfo(outfile);
}

// calculate currents and voltages
void VoltageDivider::calcValues() {
    // set node 0, 1 voltages
    setNodeVoltage(0, 0);
    setNodeVoltage(1, Vs.getVoltage());
    
    // compute loop current
    double current = Vs.getVoltage() / (R1.getResistance() + R2.getResistance());

    // set Vs current
    Vs.setCurrent(current);

    // set node 2 voltage
    setNodeVoltage(2, current * R2.getResistance());
}
