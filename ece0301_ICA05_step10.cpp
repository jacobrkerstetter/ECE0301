#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// function prototypes
bool OR(bool, bool, bool);
bool AND(bool, bool, bool);
int getBit(double, int);
string minterm(int);
bool minterm(bool, bool, bool, int);
string maxterm(int);
bool maxterm(bool, bool, bool, int);
void truthTableCSOP(ofstream&, int);
void truthTableCPOS(ofstream&, int);
string CSOP(int);
bool CSOP(bool, bool, bool, int);
string CPOS(int);
bool CPOS(bool, bool, bool, int);

int main() {	
	// define an ifstream object for file input
	ifstream infile("Bool_func_3var.txt");
	
	// create strings to hold first and second lines
	string firstline, secondline; 
	getline(infile, firstline);
	getline(infile, secondline);
	
	// check the infile to make sure the first 2 lines read correctly
	if (firstline != "Boolean function of three variables" || secondline.substr(0,16) != "function index =")
		exit(EXIT_FAILURE);
	
	// create a variable to read the input number into and read it
	int inputNum;
	inputNum = stoi(secondline.substr(17, secondline.length() - 17));
	
	// define an ofstream object for file output
	ofstream outfile("Bool_func_3var_CSOP_CPOS.txt");
	
	// dispplay the introductory message to outfile
	outfile << "ECE 0301: Boolean Functions of 3 Variables." << endl;
	outfile << "Realization in Canonical Forms.\n" << endl;
	
	// call the CSOP function with the inputNum and write to file
	string mintermString;
	mintermString = CSOP(inputNum);
	
	outfile << "CSOP: f" << inputNum << " = " << mintermString << endl << endl;
	
	// call the truthTable function to print a CSOP table to outfile
	truthTableCSOP(outfile, inputNum);
	
	// call the CPOS function with the inputNum and write to file
	string maxtermString;
	maxtermString = CPOS(inputNum);
	
	outfile << "\nCPOS: f" << inputNum << " = " << maxtermString << endl << endl;
	
	// call the truthTable function to print a CPOS table to outfile
	truthTableCPOS(outfile, inputNum);
	
	return 0;
} // end main

// function declaration of OR
bool OR(bool x, bool y, bool z) {
	if (x + y + z >= 1)
		return true;
	
	return false;
} // end OR

// function declaration of AND
bool AND(bool x, bool y, bool z) {
	if (x + y + z == 3)
		return true;
		
	return false;
} // end AND

// function declaration for getBit, returns bit at given index for int n
int getBit(double index, int n) {
	return (n / (int)pow(2.0, index)) % 2;
} // end getBit

// function declaration for returning a minterm
string minterm(int n) {
	string minterm = "";
	
	// determine the bit for each index and correspondingly complement the variable
	// and then add it to the empty string
	if (getBit(2, n) == 1)
		minterm += "x";
	else
		minterm += "x\'";
	if (getBit(1, n) == 1)
		minterm += "y";
	else
		minterm += "y\'";
	if (getBit(0, n) == 1)
		minterm += "z";
	else
		minterm += "z\'";
		
	return minterm;
} // end minterm step 4

bool minterm(bool x, bool y, bool z, int n) {
	if (getBit(2, n) == 0)
		x = !x;
	if (getBit(1, n) == 0)
		y = !y;
	if (getBit(0, n) == 0)
		z = !z;
		
	return AND(x, y, z);
} // end minterm step 6

// function declaration for returning a maxterm
string maxterm(int n) {
	string maxterm = "";
	
	// determine the bit for each index and correspondingly complement the variable
	// and then add it to the empty string
	if (getBit(2, n) == 0)
		maxterm += "x + ";
	else
		maxterm += "x\' + ";
	if (getBit(1, n) == 0)
		maxterm += "y + ";
	else
		maxterm += "y\' + ";
	if (getBit(0, n) == 0)
		maxterm += "z";
	else
		maxterm += "z\'";
		
	return maxterm;
} // end maxterm

// overloaded definition of maxterm
bool maxterm(bool x, bool y, bool z, int n) {
	if (getBit(2, n) == 1)
		x = !x;
	if (getBit(1, n) == 1)
		y = !y;
	if (getBit(0, n) == 1)
		z = !z;
		
	return OR(x, y, z);
} // end maxterm

// function declaration for truthTable
void truthTableCSOP(ofstream &outfile, int index) {
		
	// indicate the function index
	outfile << "Truth table for CSOP form of function " << index << "." << endl << endl;
	
	// write the table headers and line of dashes
	outfile << "x\ty\tz\tf(x,y,z)" << endl;
	outfile << "--------------------------------" << endl;
	
	// declare bool vars x, y, z, and f
	bool x, y, z, f;
	
	// loop from 0 - 7 to display minterm truth table
	for (int i = 0; i < 8; i++) {
		// calculate values for x, y, z, and f
		if (i % 2 == 0) 
			z = false;
		else
			z = true;
			
		if ((i >> 1) % 2 == 0)
			y = false;
		else 
			y = true;
			
		if ((i >> 2) % 2 == 0)
			x = false;
		else
			x = true;
			
		f = CSOP(x, y, z, index);
		
		// display the values to a new line in the truth table
		outfile << x << "\t" << y << "\t" << z << "\t" << f << endl;
	}
		 
} // end truthTableCSOP

// function declaration for truthTable
void truthTableCPOS(ofstream &outfile, int index) {
		
	// write the intro message
	outfile << "Truth table for CPOS form of function " << index << "." << endl << endl;
		
	// write the table headers and line of dashes
	outfile << "x\ty\tz\tf(x,y,z)" << endl;
	outfile << "--------------------------------" << endl;
	
	// declare bool vars x, y, z, and f
	bool x, y, z, f;
	
	// loop from 0 - 7 to display minterm truth table
	for (int i = 0; i < 8; i++) {
		// calculate values for x, y, z, and f
		if (i % 2 == 0) 
			z = false;
		else
			z = true;
			
		if ((i >> 1) % 2 == 0)
			y = false;
		else 
			y = true;
			
		if ((i >> 2) % 2 == 0)
			x = false;
		else
			x = true;
			
		f = CPOS(x, y, z, index);

		// display the values to a new line in the truth table
		outfile << x << "\t" << y << "\t" << z << "\t" << f << endl;
	}
		 
} // end truthTableCPOS

// function definition for the CSOP function
string CSOP(int index) {
	
	// check for valid input
	if (index < 0 || index > 255) {
		cout << "ERROR! Function index out of range.";
		exit(EXIT_FAILURE);
	}
	
	// declare a string to store the expression, n for the minterm we're on
	// and count to store what bit we are on
	string expression;
	int n = 0;
	double count = 7;
	
	// loop to find the binary value of the index and add (or not) the minterm to the string
	while(index != 0) {
		if (index >= pow(2.0, count)) {
			index -= pow(2.0, count);
			
			expression += minterm(n);
			
			// if there will be another midterm, add a plus
			if (index != 0)
				expression += " + ";
			}
		
		count--;
		n++;
	}
		
	return expression;
} // end CSOP

// function definition for the overloaded CSOP
bool CSOP(bool x, bool y, bool z, int index) {
	
	// check if the index to the CSOP function is valid
	if (index < 0 || index > 255) {
		cout << "ERROR! Function index out of range.";
		exit(EXIT_FAILURE);
	}
	
	// initialize bool for return value
	bool retVal = false;
	
	// initialize a count and n for the current minterm
	double count = 7;
	int n = 0;
	
	// loop through to find minterms and or them with retVal
	while (index != 0) {
		if (index >= pow(2.0, count)) {
			retVal =  retVal || minterm(x, y, z, n);
			
			index -= pow(2.0, count);
		}
		
		count--;
		n++;
	}
	
	return retVal;
	
} // end CSOP

// function declaration for the CPOS function
string CPOS(int index) {
	// check for valid input
	if (index < 0 || index > 255) {
		cout << "ERROR! Function index out of range.";
		exit(EXIT_FAILURE);
	}
	
	// declare a string to store the expression, n for the minterm we're on
	// and count to store what bit we are on
	string expression;
	int n = 0;
	double count = 7;
	
	// loop to find each bit and add (or not) the maxterm to the string
	while(index != 0) {
		if (index < pow(2.0, count)) 
			expression += "(" + maxterm(n) + ")";
		else
			index -= pow(2.0, count);
		
		count--;
		n++;
	}
		
	return expression;
} // end CPOS

// function definition for the overloaded CPOS
bool CPOS(bool x, bool y, bool z, int index) {
	
	// check if the index to the CSOP function is valid
	if (index < 0 || index > 255) {
		cout << "ERROR! Function index out of range.";
		exit(EXIT_FAILURE);
	}
	
	// initialize bool for return value
	bool retVal = true;
	
	// initialize a count and n for the current maxterm
	double count = 7;
	int n = 0;
	
	// loop to find each bit and add (or not) the maxterm to the string
	// loop through to find maxterm and or them with retVal
	while (index != 0) {
		if (index >= pow(2.0, count)) {
			retVal = retVal&&maxterm(x, y, z, n);
			index -= pow(2.0, count);
		}
		
		count--;
		n++;
	}
	
	return !retVal;
} // end CPOS
