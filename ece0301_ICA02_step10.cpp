// import useful headers
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	// display intro message
	cout << "ECE 0301 Propositional Logic Example" << endl;
	
	// declare string variables with the three propositions, P1, P2, and P3
	string P1 = "Pigs can fly.", P2 = "Earth is flat.", P3 = "The moon is cheese.";
	
	// display the 3 propositions to the screen
	cout << "\nP1: " << P1 << endl;
	cout << "P2: " << P2 << endl;
	cout << "P3: " << P3 << endl;
	
	// declare bool variables to hold the truth of the propositions
	bool P1Truth, P2Truth, P3Truth;
	
	// prompt the user to input the truth of each proposition
	// store in the declared bools
	cout << "\nEnter P1 truth value: ";
	cin >> P1Truth;
	
	cout << "Enter P2 truth value: ";
	cin >> P2Truth;
	
	cout << "Enter P3 truth value: ";
	cin >> P3Truth;
	
	// display what the user has entered
	cout << "\nYou entered: P1 = " << boolalpha << P1Truth
		 << ", P2 = " << boolalpha << P2Truth
		 << ", P3 = " << boolalpha << P3Truth << ".\n" << endl;
		 
	// declare a fourth bool to hold the compound proposition
	bool P4Truth;
	
	// compute the truth of P4 and store in the variable based on users inputs
	// for the truth of the original statements
	P4Truth = P1Truth && !P2Truth && P3Truth;
	
	// display the truths in an outputted table
	cout << "Truth table:\n";
	cout << "Proposition\tTruth Value" << endl;
	cout << "-----------\t-----------" << endl; 
	cout << "P1\t\t" << boolalpha << P1Truth << endl;
	cout << "P2\t\t" << boolalpha << P2Truth << endl;
	cout << "P3\t\t" << boolalpha << P3Truth << endl;
	cout << "P4\t\t" << boolalpha << P4Truth << endl;
	
	// declare another bool for another compound proposition
	bool P5Truth;
	
	// compute the truth of P5 with a combination of logical operators
	P5Truth = !P1Truth || P2Truth || P3Truth;
	
	// display P5 in the table
	cout << "P5\t\t" << boolalpha << P5Truth << endl;
	
	// declare a bool for the sixth proposition
	// compute the truth of P6 with a combination of logical and mathematical operators
	// only 1 of them is true, other 2 are false
	bool P6Truth = P1Truth + P2Truth + P3Truth == 1;
	
	// display the value of P6 in the table
	cout << "P6\t\t" << boolalpha << P6Truth << endl;
	
	// declare a bool for the seventh proposition
	// compute the truth of none being true
	bool P7Truth = P1Truth + P2Truth + P3Truth == 0;
	
	// display the value of P7 in the table
	cout << "P7\t\t" << boolalpha << P7Truth << endl;
	
	// declare a bool for the eight proposition
	// compute the truth of a majority being true
	bool P8Truth = P1Truth + P2Truth + P3Truth >= 2;
	
	// display the value of P7 in the table
	cout << "P8\t\t" << boolalpha << P8Truth << endl;
	
	// declare a bool for the ninth proposition
	// compute the truth and store in the variable
	bool P9Truth = !P1Truth && (P2Truth + P3Truth == 1) == 1;
	
	// display the value of P7 in the table
	cout << "P9\t\t" << boolalpha << P9Truth << endl;
	
	return 0;
}
