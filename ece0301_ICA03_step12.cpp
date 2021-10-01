#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	// display introductory message
	cout << "ECE 0301 - Vectors in R2 and Complex Numbers" << endl;
	cout << "Please enter two numbers, separated by a space," << endl;
	cout << "that will represent a vector or complex numbers.\n\n";
	
	// cin the two numbers into two double variables
	double num1, num2;
	
	cin >> num1;
	cin >> num2;
	
	// use ignore to clear the newline character
	cin.ignore();
	
	// display the numbers back to the user
	cout << setprecision(3) << fixed << "You entered " << num1 << " and " << num2 << ".\n\n";
	
	// ask the user to end the type of coordinates they want to use
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?\n";
	cout << "Please enter a single character as your choice.\n";
	
	// store the user's coordinate choice in a string variable
	string coordChoice;
	
	getline(cin, coordChoice);
	
	 // declare cartesian and polar coordinates for the second set
	double r1, theta1;
	double x1, y1;
	
	// switch case to decide what type of coordinates they used
	switch (coordChoice[0]) {
		case 'c':
		case 'C':
			// return the type they chose
			cout << "You entered Cartesian coordinates.\n";
			
			// evaluate and return the equivalent polar coords
			// num1 = x, num2 = y
			x1 = num1;
			y1 = num2;
			
			r1 = sqrt(pow(x1, 2.0) + pow(y1, 2.0));
			
			// if/else if/else statement to calculate theta
			if (x1 >= 0)
				theta1 = atan(y1 / x1);
			else if (x1 < 0 && y1 >= 0)
				theta1 = atan(y1 / x1) + M_PI;
			else
				theta1 = atan(y1 / x1) - M_PI;
				
			// display the polar coordinates to the user
			cout << "The equivalent polar coordinates are:\n";
			cout << setprecision(3) << fixed << "R = " << r1 << ", theta = " << theta1 
			     << endl;
			
			break;
		
		case 'p':
		case 'P':
			// return the type they chose
			cout << "You entered polar coordinates.\n";
			
			// evaluate and return the equivalent cartesian coords
			// make sure R >= 0 and -pi <= theta <= pi
			// num1 = R, num2 = theta
			r1 = num1;
			theta1 = num2;
			
			if (r1 < 0 || theta1 < -M_PI || theta1 > M_PI) {
				cout << "ERROR! Invalid polar coordinates, exiting.";
				return -1;
			}
			
			x1 = r1 * cos(theta1);
			y1 = r1 * sin(theta1);
			
			cout << "The equivalent Cartesian coordinates are:\n";
			cout << setprecision(3) << fixed << "x = " << x1 << ", y = " << y1 << endl;
			
			break;
			
		default:
			cout << "ERROR! Invalid selection, exiting.";
			return -1;
	}
	
	// prompt the user for two new numbers and store them as num3 and num4
	double num3, num4;
	
	cout << "Please enter another pair of numbers, separated by a\n"
		 << "space, to represent a second vector or complex number\n\n";
		 
	cin >> num3;
	cin >> num4;
	
	// use cin.ignore() to clear the newline character
	cin.ignore();
	
	// display the numbers back to the user
	cout << setprecision(3) << fixed << "You entered " << num3 << " and " << num4 << ".\n\n";
	
	// ask the user to end the type of coordinates they want to use
	cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?\n";
	cout << "Please enter a single character as your choice.\n";
	
	// store the user's second coordinate choice in a string variable
	string coordChoice2;
	
	getline(cin, coordChoice2);
	
	// declare cartesian and polar coordinates for the second set
	double r2, theta2;
	double x2, y2;
	
	// switch case to decide what type of coordinates they used
	switch (coordChoice2[0]) {
		case 'c':
		case 'C':
			// return the type they chose
			cout << "You entered Cartesian coordinates.\n";
			
			// evaluate and return the equivalent polar coords
			// num3 = x, num4 = y
			x2 = num3;
			y2 = num4;
			
			r2 = sqrt(pow(x2, 2.0) + pow(y2, 2.0));
			
			// if/else if/else statement to calculate theta
			if (x2 >= 0)
				theta2 = atan(y2 / x2);
			else if (x2 < 0 && y2 >= 0)
				theta2 = atan(y2 / x2) + M_PI;
			else
				theta2 = atan(y2 / x2) - M_PI;
				
			// display the polar coordinates to the user
			cout << "The equivalent polar coordinates are:\n";
			cout << setprecision(3) << fixed << "R = " << r2 << ", theta = " << theta2 << endl;
			
			break;
		
		case 'p':
		case 'P':
			// return the type they chose
			cout << "You entered polar coordinates.\n";
			
			// evaluate and return the equivalent cartesian coords
			// make sure R >= 0 and -pi <= theta <= pi
			// num3 = R, num4 = theta
			r2 = num3;
			theta2 = num4;
			
			if (r2 < 0 || theta2 < -M_PI || theta2 > M_PI) {
				cout << "ERROR! Invalid polar coordinates, exiting.";
				return -1;
			}
			
			x2 = r2 * cos(theta2);
			y2 = r2 * sin(theta2);
			
			cout << "The equivalent Cartesian coordinates are:\n";
			cout << setprecision(3) << fixed << "x = " << x2 << ", y = " << y2 << endl;
			
			break;
			
		default:
			cout << "ERROR! Invalid selection, exiting.";
			return -1;
	}
	
	// ask if user wants vectors or complex numbers
	cout << "\nDo the values you entered represent vectors (v) or complex numbers (c)?\n"
		 << "Please enter a single character as your choice.\n";
		 
	// declare a string to hold this choice
	string vectorOrComplex;
	
	getline(cin, vectorOrComplex);
	
	switch (vectorOrComplex[0]) {
		// cases for if they choose vector
		case 'v':
		case 'V':
			// the user wanted vector form, display the 2 vectors
			cout << setprecision(3) << fixed << "Cartesian:\t" 
				 << "v1 = (" << x1 << ", " << y1 << ")\n"
				 << "Polar:\t\tv1 = (" << r1 << ", " << theta1 << ")\n\n";
				 
			cout << setprecision(3) << fixed << "Cartesian:\t" 
				 << "v2 = (" << x2 << ", " << y2 << ")\n"
				 << "Polar:\t\tv2 = (" << r2 << ", " << theta2 << ")\n\n";
			
			// ask the use which sum or difference of vectors they want
			cout << "Which of the following vector sums or differences\n"
				 << "would you like to compute?\n"
				 << "(1) v1 + v2\n"
				 << "(2) v1 - v2\n"
				 << "(3) v2 - v1\n"
				 << "(4) -v1 - v2\n\n";
				 
			// store choice in an int
			int vectorSumChoice;
			
			cin >> vectorSumChoice;
			
			// use a switch case to handle the users choice
			// declare variables for vector number computations
			double sumX, sumY, RNew, thetaNew, diffY, diffX;
			
			switch (vectorSumChoice) {
				case 1: // add the two vectors
					// store x1+x2 and y1+y2 in vars sumX and sumY, then convert to RNew and thetaNew
					sumX = x1+x2;
					sumY = y1+y2;
					RNew = sqrt(pow(sumX, 2.0) + pow(sumY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (sumX >= 0)
						thetaNew = atan(sumY / sumX);
					else if (sumX < 0 && sumY >= 0)
						thetaNew = atan(sumY / sumX) + M_PI;
					else
						thetaNew = atan(sumY / sumX) - M_PI;
						
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "v_sum = (" << sumX << ", " << sumY << ")\n";
					cout << "Sum, Polar:\tv_sum = (" << RNew << ", " << thetaNew << ")\n\n";
						 
					break;
				
				case 2: // subtract v2 from v1
					// store x1-x2 and y1-y2 in vars diffX and diffY, then convert to RNew and thetaNew
					diffX = x1-x2;
					diffY = y1-y2;
					RNew = sqrt(pow(diffX, 2.0) + pow(diffY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (diffX >= 0)
						thetaNew = atan(diffY / diffX);
					else if (diffX < 0 && diffY >= 0)
						thetaNew = atan(diffY / diffX) + M_PI;
					else
						thetaNew = atan(diffY / diffX) - M_PI;
						
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "v_sum = (" << diffX << ", " << diffY << ")\n";
					cout << "Sum, Polar:\tv_sum = (" << RNew << ", " << thetaNew << ")\n\n";
						 
					break;
				
				case 3: // subtract v1 from v2
					// store x2-x1 and y2-y1 in vars diffX and diffY, then convert to RNew and thetaNew
					diffX = x2-x1;
					diffY = y2-y1;
					RNew = sqrt(pow(diffX, 2.0) + pow(diffY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (diffX >= 0)
						thetaNew = atan(diffY / diffX);
					else if (diffX < 0 && diffY >= 0)
						thetaNew = atan(diffY / diffX) + M_PI;
					else
						thetaNew = atan(diffY / diffX) - M_PI;
						
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "v_sum = (" << diffX << ", " << diffY << ")\n";
					cout << "Sum, Polar:\tv_sum = (" << RNew << ", " << thetaNew << ")\n\n";
						 
					break;
				
				case 4: // sutract v2 from -v1
					// store -x1-x2 and -y1-y2 in vars diffX and diffY, then convert to RNew and thetaNew
					diffX = -x1-x2;
					diffY = -y1-y2;
					RNew = sqrt(pow(diffX, 2.0) + pow(diffY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (diffX >= 0)
						thetaNew = atan(diffY / diffX);
					else if (diffX < 0 && diffY >= 0)
						thetaNew = atan(diffY / diffX) + M_PI;
					else
						thetaNew = atan(diffY / diffX) - M_PI;
						
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "v_sum = (" << diffX << ", " << diffY << ")\n";
					cout << "Sum, Polar:\tv_sum = (" << RNew << ", " << thetaNew << ")\n\n";
						 
					break;
				
				// not valid input
				default:
					cout << "ERROR! Invalid selection, exiting.";
					return -1;
			}
			
			// declare a variable to hold dot product 1 and 2
			double dotProd1, dotProd2;
			
			// computer dotProd1 using method 1 and dotProd2 with method 2
			dotProd1 = r1*r2*cos(theta1-theta2);
			dotProd2 = x1*x2 + y1*y2;
			
			// display the inner products to the user
			cout << "The inner product of v1 and v2 using polar coordinates is " << dotProd1 << endl;
			cout << "The inner product of v1 and v2 using polar coordinates is " << dotProd2 << endl;
			
			break;
			
		// cases for if they choose complex number
		case 'c':
		case 'C':
		
			// display the complex numbers in cartesian and polar form
			// need 2 cases for each for if y1 or theta is negative to fix the output
			if (y1 < 0) {
				cout << setprecision(3) << fixed << "Cartesian:\t" 
					 << "z1 = " << x1 << " - j " << -y1;
			}
			else {
				cout << setprecision(3) << fixed << "Cartesian:\t" 
					 << "z1 = " << x1 << " + j " << y1;
			}
			if (theta1 < 0) {
				cout << "\nPolar:\t\tz1 = " << r1 << " exp(-j " << -theta1 << ")\n\n";
			}
			else {
				cout << "\nPolar:\t\tz1 = " << r1 << " exp(j " << theta1 << ")\n\n";
			}
			if (y2 < 0) {
				cout << setprecision(3) << fixed << "Cartesian:\t" 
					 << "z2 = " << x2 << " - j " << -y2;
			}
			else {
				cout << setprecision(3) << fixed << "Cartesian:\t" 
					 << "z2 = " << x2 << " + j " << y2;
			}
			if (theta2 < 0) {
				cout << "\nPolar:\t\tz1 = " << r2 << " exp(-j " << -theta2 << ")\n\n";
			}
			else {
				cout << "\nPolar:\t\tz1 = " << r2 << " exp(j " << theta2 << ")\n\n";
			}
			
			// ask the user which sum or difference of complex numbers they want
			cout << "Which of the following sums or differences\n"
				 << "would you like to compute?\n"
				 << "(1) z1 + z2\n"
				 << "(2) z1 - z2\n"
				 << "(3) z2 - z1\n"
				 << "(4) -z1 - z2\n\n";
			
			// store choice in an int
			int complexSumChoice;
			
			cin >> complexSumChoice;
			
			// use a switch case to handle the users choice
			
			switch (complexSumChoice) {
				case 1: // add the two vectors, use if statements for if the second component is negative
				
					// store x1+x2 and y1+y2 in vars sumX and sumY, then convert to RNew and thetaNew
					sumX = x1+x2;
					sumY = y1+y2;
					RNew = sqrt(pow(sumX, 2.0) + pow(sumY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (sumX >= 0)
						thetaNew = atan(sumY / sumX);
					else if (sumX < 0 && sumY >= 0)
						thetaNew = atan(sumY / sumX) + M_PI;
					else
						thetaNew = atan(sumY / sumX) - M_PI;
					
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "z_sum = " << sumX;
					if (sumY < 0) 
						cout << " - j " << -sumY << endl;
					else
						cout << " + j " << sumY << endl;
							 
					cout << "Sum, Polar:\tz_sum = " << RNew;
					
					if (thetaNew < 0)
						cout << " exp(-j " << -thetaNew << ")\n\n";
					else
						cout << " exp(j " << thetaNew << ")\n\n";
						
					break;
				
				case 2: // subtract z2 from z1
					// store x1-x2 and y1-y2 in vars diffX and diffY, then convert to RNew and thetaNew
					diffX = x1-x2;
					diffY = y1-y2;
					RNew = sqrt(pow(diffX, 2.0) + pow(diffY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (diffX >= 0)
						thetaNew = atan(diffY / diffX);
					else if (diffX < 0 && diffY >= 0)
						thetaNew = atan(diffY / diffX) + M_PI;
					else
						thetaNew = atan(diffY / diffX) - M_PI;
					
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "z_sum = " << diffX;
					if (diffY < 0) 
						cout << " - j " << -diffY << endl;
					else
						cout << " + j " << diffY << endl;
							 
					cout << "Sum, Polar:\tz_sum = " << RNew;
					
					if (thetaNew < 0)
						cout << " exp(-j " << -thetaNew << ")\n\n";
					else
						cout << " exp(j " << thetaNew << ")\n\n";
						
					break;
				
				case 3: // sutract z1 from z2
					// store x2-x1 and y2-y1 in vars diffX and diffY, then convert to RNew and thetaNew
					diffX = x2-x1;
					diffY = y2-y1;
					RNew = sqrt(pow(diffX, 2.0) + pow(diffY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (diffX >= 0)
						thetaNew = atan(diffY / diffX);
					else if (diffX < 0 && diffY >= 0)
						thetaNew = atan(diffY / diffX) + M_PI;
					else
						thetaNew = atan(diffY / diffX) - M_PI;
					
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "z_sum = " << diffX;
					if (diffY < 0) 
						cout << " - j " << -diffY << endl;
					else
						cout << " + j " << diffY << endl;
							 
					cout << "Sum, Polar:\tz_sum = " << RNew;
					
					if (thetaNew < 0)
						cout << " exp(-j " << -thetaNew << ")\n\n";
					else
						cout << " exp(j " << thetaNew << ")\n\n";
						
					break;
					
				case 4: // subtract z2 from -z1
					// store -x1-x2 and -y1-y2 in vars diffX and diffY, then convert to RNew and thetaNew
					diffX = (-x1)-x2;
					diffY = (-y1)-y2;
					RNew = sqrt(pow(diffX, 2.0) + pow(diffY, 2.0));
					
					// if/else if/else statement to calculate thetaNew
					if (diffX >= 0)
						thetaNew = atan(diffY / diffX);
					else if (diffX < 0 && diffY >= 0)
						thetaNew = atan(diffY / diffX) + M_PI;
					else
						thetaNew = atan(diffY / diffX) - M_PI;
					
					cout << setprecision(3) << fixed << "Sum, Cartesian:\t" 
						 << "z_sum = " << diffX;
					if (diffY < 0) 
						cout << " - j " << -diffY << endl;
					else
						cout << " + j " << diffY << endl;
							 
					cout << "Sum, Polar:\tz_sum = " << RNew;
					
					if (thetaNew < 0)
						cout << " exp(-j " << -thetaNew << ")\n\n";
					else
						cout << " exp(j " << thetaNew << ")\n\n";
						
					break;
				
				default:
					cout << "ERROR! Invalid selection, exiting.";
					return -1;
				}
			
			// declare variables to hold the components of the products from polar and rect. methods
			double polarProdFirstTerm, polarProdSecondTerm, rectProdFirstTerm, rectProdSecondTerm;
			
			// compute the dot products the polar method
			polarProdFirstTerm = r1*r2;
			polarProdSecondTerm = theta1+theta2;
			
			// compute the dot products the rectangular methods
			rectProdFirstTerm = x1*x2 - y1*y2;
			rectProdSecondTerm = x1*y2 + y1*x2;
			
			// convert the polar coords to cartesian to prove correct methods
			// declare variables to hold the terms
			double checkTerm1, checkTerm2;
		
			// use x = rcos(theta) and y = rsin(theta)
			checkTerm1 = polarProdFirstTerm * cos(polarProdSecondTerm);
			checkTerm2 = polarProdFirstTerm * sin(polarProdSecondTerm);
			
			// display all outputs
			cout << "Product, polar:\t\tz1 * z2 = " << polarProdFirstTerm << " exp(j " << polarProdSecondTerm << ")\n)";
			cout << "Product, Cartesian:\tz1 * z2 = " << rectProdFirstTerm << " + j " << rectProdSecondTerm << ")\n\n)";
			cout << "Polar, converted to Cartesian: z1 * z2 = " << checkTerm1 << " + j " << checkTerm2 << ")\n\n)";
			
			break;
		
		default:
			cout << "ERROR! Invalid selection, exiting.";
			return -1;
	}
	
	return 0;
}
