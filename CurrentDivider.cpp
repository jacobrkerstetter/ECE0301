#include "CurrentDivider.h"
#include <fstream>
using namespace std;

// constructors
CurrentDivider::CurrentDivider() : Network(2) {
    // set initial values
    Is.setCurrent(1);
    R1.setResistance(1000);
    R2.setResistance(1000);

    // connect components
    connectComponent(&Is, 0, 1);
    connectComponent(&R1, 0, 1);
    connectComponent(&R2, 0, 1);

    calcValues();
}

CurrentDivider::CurrentDivider(double i, double Res1, double Res2) : Network(2) {
    // set initial values
    Is.setCurrent(i);
    R1.setResistance(Res1);
    R2.setResistance(Res2);

    // connect components
    connectComponent(&Is, 0, 1);
    connectComponent(&R1, 0, 1);
    connectComponent(&R2, 0, 1);

    calcValues();
}

// mutators
void CurrentDivider::setIs(double i) {
    Is.setCurrent(i);

    calcValues();
}

void CurrentDivider::setRs(double Res1, double Res2) {
    R1.setResistance(Res1);
    R2.setResistance(Res2);

    calcValues();
}

// other member functions
void CurrentDivider::calcValues() {
    // set Node 0 to 0 V
    setNodeVoltage(0, 0);

    // compute Req
    double Req = (R1.getResistance() * R2.getResistance()) / (R1.getResistance() + R2.getResistance());

    // set Node 1 to Is * Req
    setNodeVoltage(1, Is.getCurrent() * Req);
}

void CurrentDivider::reportInfo(ofstream &outfile) {
    outfile << endl;

    for (int i = 0; i < 48; i++)
        outfile << "-";
    outfile << "\n\nData for Electric Network # " << getIndex() << ":\n";
    outfile << "Network # " << getIndex() << " is a Current Divider.\n";
    
    // call report info function
    reportNetworkInfo(outfile);

    // write about components
    outfile << "At present, there are " << Is.getNumComponents() << " components in existence.\n";

    Is.reportInfo(outfile);
    R1.reportResistorInfo(outfile);
    R2.reportResistorInfo(outfile);
}