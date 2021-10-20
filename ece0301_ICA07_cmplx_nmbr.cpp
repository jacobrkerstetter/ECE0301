#include <iostream>
#include <cmath>
using namespace std;

// class definition for ComplexNumber
class ComplexNumber {
    
    // declare private members
    private:
        double realPart;
        double imagPart;

    // declare public functions and write them
    public:
        void setRealPart(double n) { realPart = n; }
        void setImagPart(double n) { imagPart = n; }
        double getRealPart() { return realPart; }
        double getImagPart() { return imagPart; }
        double getMagnitude() { return sqrt(pow(realPart, 2) + pow(imagPart, 2)); }
        double getPhaseAngle() { return atan2(imagPart, realPart); }
}; // end ComplexNumber

int main() {
    
    // create a complex number
    ComplexNumber userNumber;

    // display intro message
    cout << "This program will calculate the magnitude and phase angle\nof a complex number\n\n";

    // display user prompt for real part
    cout << "What is the real part? ";

    // read in real part and set to the object
    double userReal;
    cin >> userReal;

    userNumber.setRealPart(userReal);

    // display user prompt for imaginary part
    cout << "What is the imaginary part? ";

    // read in imaginary part and set to the object
    double userImag;
    cin >> userImag;

    userNumber.setImagPart(userImag);

    // read out the data from the object and print to cout
    cout << "Here are the data on complex number z:" << endl;
    cout << "Real Part: " << userNumber.getRealPart() << endl;
    cout << "Imaginary Part: " << userNumber.getImagPart() << endl;
    cout << "Magnitude: " << userNumber.getMagnitude() << endl;
    cout << "Phase Angle (radians): " << userNumber.getPhaseAngle() << endl;

    return 0;
} // end main