/*
	Jacob Kerstetter
	Dr. Mahmoud
	9/1/21
	ICA 1
*/

#include <iostream> // for I/O usage
using namespace std;

int main()
{
	// print the introductory message to the program
	cout << "ECE 0301 DC Resistive Circuit Simulation\n";
	cout << "Modeled after www.falstad.com/circuit/\n";
	cout << "Circuits -> Basics -> Ohm\'s Law\n";
	
	// declare double variables for the voltage (in Volts) and both resistances (in Ohms)
	double voltage = 7200, resistance1 = 8, resistance2 = 10;
	
	// print the value of the voltage, resistance1 and resistance2 in a sentence
	cout << "Vs = " << voltage << " Volts\n";
	cout << "R1 = " << resistance1 << " Ohms\n";
	cout << "R2 = " << resistance2 << " Ohms\n";
	
	// declare variables to hold current through R1 and R2
	double current1, current2;
	
	// set these equal to the calculation for current, I = V/R
	current1 = voltage / resistance1;
	current2 = voltage / resistance2;
	
	// declare variables to hold power dissipated in each resistor
	double power1, power2;
	
	// set these equal to the calculation for power dissipation, P = I^2 * R
	power1 = current1 * current1 * resistance1;
	power2 = current2 * current2 * resistance2;
	
	// output these to the screen
	cout << "I1 = " << current1 << " Amperes\n";
	cout << "P1 = " << power1 << " Watts\n";
	cout << "I2 = " << current2 << " Amperes\n";
	cout << "P2 = " << power2 << " Watts\n";
	
	// create variable for current flowing out of it and power supplied by battery
	// current from battery is sum of currents split off of it
	// power = IV
	double batteryCurrent = current1 + current2;
	double batteryPower = batteryCurrent * voltage;
	
	// declare variables for energy supplied to the voltage source
	double energyPerSec, energyPerHr, energyPerDay, energyPerYr;
	
	// declare conversion factors for seconds in an hr, in a day, and in a year
	const int SEC_IN_HR = 3600;
	const int SEC_IN_DAY = 86400;
	const int SEC_IN_YR = SEC_IN_DAY * 365;
	
	// run the calculation for energy usage in each time frame
	// E = P * t
	energyPerSec = batteryPower * 1; // multiply by 1 sec for time
	energyPerHr = batteryPower * SEC_IN_HR;
	energyPerDay = batteryPower * SEC_IN_DAY;
	energyPerYr = batteryPower * SEC_IN_YR;
	
	// output these results to the screen
	cout << "Energy supplied in one second = " << energyPerSec << " Joules\n";
	cout << "Energy supplied in one hour = " << energyPerHr << " Joules\n";
	cout << "Energy supplied in one day = " << energyPerDay << " Joules\n";
	cout << "Energy supplied in one year = " << energyPerYr << " Joules\n";
	
	// declare variables to hold cost for each energy amount
	double costPerSec, costPerHr, costPerDay, costPerYr;
	
	// declare constant cost of electricity
	const double COST_OF_ELEC = .10;
	
	// declare constant for conversion of watts to kilowatts
	const int WATT_IN_KW = 1000;
	
	// calculate each kWh with kWh = energy / (SEC_IN_HR * WATT_IN_KW)
	// Joules = W-s, so divide by seconds per hr and watts per kw to convert
	// then multiple by .10 for cost per kWh
	costPerSec = (energyPerSec / (SEC_IN_HR * WATT_IN_KW)) * COST_OF_ELEC;
	costPerHr = (energyPerHr / (SEC_IN_HR * WATT_IN_KW)) * COST_OF_ELEC;
	costPerDay = (energyPerDay / (SEC_IN_HR * WATT_IN_KW)) * COST_OF_ELEC;
	costPerYr = (energyPerYr / (SEC_IN_HR * WATT_IN_KW)) * COST_OF_ELEC;
	
	// display the costs of electricity to the screen
	cout << "Cost of supplying energy for one second at $0.10/kWh = $" << costPerSec << endl;
	cout << "Cost of supplying energy for one hour at $0.10/kWh = $" << costPerHr << endl;
	cout << "Cost of supplying energy for one day at $0.10/kWh = $" << costPerDay << endl;
	cout << "Cost of supplying energy for one year at $0.10/kWh = $" << costPerYr << endl;
	
	return 0;
}
