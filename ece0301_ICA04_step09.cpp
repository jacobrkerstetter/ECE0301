#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	// output an intro message
	cout << "ECE 0301: Circuit Solver for Voltage Divider" << endl;
	cout << "and Wheatstone bridge example circuits." << endl;
	
	// declare an ifstream object and open the input file
	ifstream infile;
	infile.open("divider_wheatstone_circuits.txt");
	
	// read the first line and exit if it's not "Divider" or "Wheatstone"
	string circuitType;
	infile >> circuitType;
	
	// define an ofstream object to open a solutions file
	ofstream outfile;
	outfile.open("divider_wheatstone_solutions.txt");
	
	// declare the variables for circuit values
	double Vs, I, Is, I1, I2, I3, I4, I5;
	int R1, R2, R3, R4, R5, n;
	double V1, V2, V3, V4, V5;
	
	// declare a circuitNum variable to count the number circuit we are on
	int circuitNum = 1;
	
	// print intro message to outfile
	outfile << "ECE 0301: Circuit Solver for Voltage Divider" << endl;
	outfile << "and Wheatstone bridge example circuits." << endl; 
	
	do {
	
		if (circuitType != "Divider" && circuitType != "Wheatstone") {
			cout << "ERROR! Invalid header.";
			return -1;
		}
		
		// if the first line of the file is Divider, calculate I, V1, V2
		else if (circuitType == "Divider") {
			// read three more lines and store them as Vs, R1, and R2
			infile >> Vs >> R1 >> R2 >> n;
			
			// print header to outfile
			outfile << "-----\nCircuit #" << circuitNum << " (Voltage Divider)" << endl;
			
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					// print dashed line
					outfile << "---" << endl;
					// create new multiplied resistances
					int R1New = i*R1, R2New = j*R2;
					
					// calculate I and store in a double
					I = Vs / (R1New + R2New);
					
					// calculate V1 and V2 and store as ints
					V1 = Vs * ((double)R1New / (R1New + R2New));
					V2 = Vs * ((double)R2New / (R1New + R2New));
					
					// print the information that was read in to outfile
					outfile << "Source Voltage: Vs = " << Vs << " Volts." << endl;
					outfile << "Resistor: R1 = " << R1New << " Ohms." << endl;
					outfile << "Resistor: R2 = " << R2New << " Ohms.\n" << endl;
					
					// print the calculated information to outfile
					outfile << "Loop current: I = " << I << " Amperes." << endl;
					outfile << "Resistor voltage: V1 = " << V1 << " Volts." << endl;
					outfile << "Resistor voltage: V2 = " << V2 << " Volts." << endl;
				}
			}
			// increment the circuitNum variable
			circuitNum++; 
		}
		
		else {
			// read in the input values
			infile >> Vs >> Is >> R1 >> R2 >> R3 >> R4 >> R5 >> n;
			
			// print header to file
			outfile << "-----\nCircuit #" << circuitNum << " (Wheatstone Bridge)\n";
			
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						for (int l = 1; l <= n; l++) {
							for (int m = 1; m <= n; m++) {
								// calculate V1 -> V5 and I1 -> I5 using equations given
								// declare and compute a through f as given as doubles for the calculations
								double a, b, c, d, e, f;
								
								// create new values for the multiplied resistances
								int R1New = i*R1, R2New = j*R2, R3New = k*R3, R4New = l*R4, R5New = m*R5;
								
								// if the input values break the rules about div by 0 and roundoff, exit program
								if (R2New == 0 || R3New == 0 || ((Vs - Is * R4New) > -10E-13 && (Vs - Is * R4New) < 10E-13) || ((Vs + Is * R5New) > -10E-13 && (Vs + Is * R5New) < 10E-13)) {
									cout << "ERROR! Unstable floating-point division.";
									return -1;
								}
								
								a = 1 + ((double)R4New/R2New);
								b = Vs - (Is * R4New);
								c = 1 + ((double)R5New/R3New);
								d = Vs + (Is * R5New);
								e = (double)R1New/R2New;
								f = (double)R1New/R3New;
								
								// declare and compute w through z from the previous variables
								double w, x, y, z;
								
								w = (a + e) / b;
								x = f/b;
								y = e/d;
								z = (c + f) / d;
								
								// compute V3 and V2 from eqs. 4 and 5
								V3 = (y - w) / (x*y - w*z);
								V2 = (1 - x*V3) / w;
								
								// compute V1 from eq. 3
								V1 = e*V2 + f*V3;
								
								// compute V4 and V5 from eqs. 1 and 2
								V4 = Vs - V1 - V2;
								V5 = Vs - V1 - V3;
								
								// use Ohm's law to solve for unknown currents
								I1 = V1/R1New;
								I2 = V2/R2New;
								I3 = V3/R3New;
								I4 = V4/R4New;
								I5 = V5/R5New;
								
								// print dashed line to file
								outfile << "---" << endl;
								
								// print given variables to file
								outfile << "Source Voltage: Vs = " << Vs << " Volts." << endl;
								outfile << "Source Current: Is = " << Is << " Amperes." << endl;
								outfile << "Resistor: R1 = " << R1New << " Ohms." << endl;
								outfile << "Resistor: R2 = " << R2New << " Ohms." << endl;
								outfile << "Resistor: R3 = " << R3New << " Ohms." << endl;
								outfile << "Resistor: R4 = " << R4New << " Ohms." << endl;
								outfile << "Resistor: R5 = " << R5New << " Ohms.\n" << endl;
								
								// print variables solved for to file
								outfile << "Resistor voltage: V1 = " << V1 << " Volts." << endl;
								outfile << "Resistor current: I1 = " << I1 << " Amperes." << endl;
								outfile << "Resistor voltage: V2 = " << V2 << " Volts." << endl;
								outfile << "Resistor current: I2 = " << I2 << " Amperes." << endl;
								outfile << "Resistor voltage: V3 = " << V3 << " Volts." << endl;
								outfile << "Resistor current: I3 = " << I3 << " Amperes." << endl;
								outfile << "Resistor voltage: V4 = " << V4 << " Volts." << endl;
								outfile << "Resistor current: I4 = " << I4 << " Amperes." << endl;
								outfile << "Resistor voltage: V5 = " << V5 << " Volts." << endl;
								outfile << "Resistor current: I5 = " << I5 << " Amperes." << endl;
							}
						}
					}
				}
			}
			
			// increment the circuit number
			circuitNum++;
		}
	} while (infile >> circuitType);
	
	return 0;
}
