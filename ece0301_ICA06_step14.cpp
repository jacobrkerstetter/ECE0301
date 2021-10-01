#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>

// include the preprocessing drive we created
#include "array_dim.h"
using namespace std;

// function prototypes
int readDim(ifstream&, double[][DIM], double[]);
void writeInfo(int, double[][DIM], double[], double[], ofstream&);
void matVecMult(double[][DIM], double[], double[]);
void matDisplay(double[][DIM], int, ofstream&);
void copyPart(double[][DIM], double[][DIM], int, int, int);
double determinant(double[][DIM], int n);
void replaceCol(double[][DIM], double[], double[][DIM], int);

int main() {

    // define an ofstream object to read input file
    ofstream outfile("ECE0301_ICA06_Axeqb_solution.txt");
    
    // create infile object
    ifstream infile("ECE0301_ICA06_Axeqb_problem.txt");

    // create blank arrays A and b
    double A[DIM][DIM];
    double b[DIM];

    // get N from the readDim function
    int N = readDim(infile, A, b);

    // call determinant function and write to output file
    int det = determinant(A, N);

    // define a new matrix to replace the column with b and x for solutions
    double replace[DIM][DIM];
    double x[DIM];

    // declare a variable to store determinant of replace matrix
    int replaceDet = 0;

    // loop over columns of A and replace columns, write to output, and compute determinant
    for (int col = 0; col < DIM; col++) {
        // replace the col
        replaceCol(A, b, replace, col);

        // calculate determinant
        replaceDet = determinant(replace, N);

        x[col] = (replaceDet / det);
    }

    // call write info function to write this to outfile
    writeInfo(N, A, b, x, outfile);
    
    return 0;
} // end main

int readDim(ifstream &infile, double A[][DIM], double b[]) {
    // read the first line to garbage
    string firstLine;
    getline(infile, firstLine);

    // string to read N into
    string N;
    getline(infile, N);

    // error check the garbage line to make sure it aligns with the problem type
    // and the N =
    if (firstLine != "ECE 0301: Ax = b Problem" || N.substr(0,4) != "N = ") {
        cout << "ERROR! Input file format error";
        exit(EXIT_FAILURE);
    }

    if (stoi(N.substr(4,1)) != DIM) {
        cout << "ERROR! Dimension mismatch, N != DIM.";
        exit(EXIT_FAILURE);
    }

    // also read array A and b from the file
    string ALine;
    getline(infile, ALine);

    // error check
    if (ALine != "A = ") {
        cout << "ERROR! Input file format error";
        exit(EXIT_FAILURE);
    }

    int intN = stoi(N.substr(4,1));
    
    // declare double to read in
    double readNum = 0;

    // nested for loops to fill A
    for (int i = 0; i < intN; i++) {
        for (int j = 0; j < intN; j++) {
            infile >> readNum;
            A[i][j] = readNum;
        }
    }

    // error check
    string bLine;
    infile.ignore();
    getline(infile, bLine);

    if (bLine != "b = ") {
        cout << "ERROR! Input file format error";
        exit(EXIT_FAILURE);
    }

    // read values into b
    for (int i = 0; i < DIM; i++) {
        infile >> readNum;
        b[i] = readNum;
    }

    // return the int value attached to N
    return intN;
} // end readDim

void writeInfo(int N, double A[][DIM], double b[], double x[], ofstream &outfile) {

    // write an intro message
    outfile << "ECE 0301 - Matrix-Vector Computations," << endl;
    outfile << "Determinants and Cramer's Rule." << endl << endl;

    // write the dimension to outfile
    outfile << "Global array dimension: DIM = " << DIM << endl;

    // add file read dimension
    outfile << "Input file: N = " << N << endl << endl;

    // write A as a square matrix to the file
    outfile << "A =" << endl;

    for (int i = 0; i < N; i++) {
        outfile << "[ ";

        for (int j = 0; j < N; j++) {
            outfile << setw(10) << A[i][j];
        }  

        outfile << " ] \n";
    }
    
    // write b to file
    outfile << "\nb =\n";

    for (int i = 0; i < N; i++)
        outfile << "[ " << setw(10) << b[i] << " ] \n";

    // write the product Ax to the file
    outfile << "\nProblem A * x = b:" << endl;

    for (int i = 0; i < N; i++) {
        outfile << "[ ";

        for (int j = 0; j < N; j++) {
            outfile << setw(10) << A[i][j];
        }  

        if (DIM == 2 && i == 0) {
            outfile << " ] * [ ";
            outfile << "x" << i << " ] = [ " << setw(10) << b[i] << " ]" << endl;
        }
        else if (DIM != 2 && i == DIM/2 - 1) {
            outfile << " ] * [ ";
            outfile << "x" << i << " ] = [ " << setw(10) << b[i] << " ]" << endl;
        }
        else {
            outfile << " ]   [ ";
            outfile << "x" << i << " ]   [ " << setw(10) << b[i] << " ]" << endl;
        }
    }

    // display the solution vector x
    outfile << endl << "Solution: x =" << endl;

    for (int i = 0; i < N; i++) {
        outfile << "[ " << setw(10) << x[i] << " ] \n";
    }

    // define an array to store Ax
    double sol[N];

    // compute Ax with matrix-vector multiplication function
    matVecMult(A, x, sol);

    // display the checking solution
    outfile << endl << "Checking Solution: A * x = b" << endl;

    for (int i = 0; i < N; i++) {
        outfile << "[ ";

        for (int j = 0; j < N; j++) {
            outfile << setw(10) << A[i][j];
        }  

        if (DIM == 2 && i == 0) {
            outfile << " ] * [ ";
            outfile << setw(10) << x[i] << " ] = [ " << setw(10) << sol[i] << " ]" << endl;
        }
        else if (DIM != 2 && i == DIM/2 - 1) {
            outfile << " ] * [ ";
            outfile << setw(10) << x[i] << " ] = [ " << setw(10) << sol[i] << " ]" << endl;
        }
        else {
            outfile << " ]   [ ";
            outfile << setw(10) << x[i] << " ]   [ " << setw(10) << sol[i] << " ]" << endl;
        }
    }

    // display the error of Ax = b
    outfile << endl << "Error in RHS values:" << endl;

    for (int i = 0; i < DIM; i++)
        outfile << "[" << setw(10) << sol[i] - b[i] << " ]" << endl;
    
} // end writeInfo

void matVecMult(double A [][DIM], double x[], double prod[]) {
    
    // initialize a sum for each result vector element
    double sum = 0;
    
    // loop to multiply the matrix A and vector x
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            sum += A[i][j] * x[j];
        }

        // add the element to the product vector and reset element value (sum)
        prod[i] = sum;
        sum = 0;
    }
} // end matVecMult

void matDisplay(double A[][DIM], int n, ofstream &outfile) {
    
    // loop over the input number of rows and cols and print to outfile
    for (int i = 0; i < n; i++) {
        outfile << "[ ";

        for (int j = 0; j < n; j++) {
            outfile << setw(10) << A[i][j];
        }
        outfile << " ]" << endl;
    }

} // end matDisplayA

void copyPart(double in[][DIM], double out[][DIM], int i, int j, int n) {
    // initialize rows and cols
    int row = 0, col = 0;
    
    for (int k = 0; k < n; k++) {
        // if the row k we are looking at is i, skip
        if (k == i)
            continue;

        for (int m = 0; m < n; m++) {
            // if the col m we are looking at is j, skip
            if (m == j)
                continue;
            
            // if it is a valid row/col, add to the outgoing matrix
            out[row][col] = in[k][m];
            col++;
        }

        // reset the columns and iterate to the next row
        col = 0;
        row++;
    }
} // end copyPart

double determinant(double A[][DIM], int n) {
    // base case
    if (n == 1) return A[0][0];

    // initialize determinant to 0
    double det = 0;

    // declare the submatrix 
    double subMat[DIM][DIM];

    // loop over elements of A to copy to sub matrix (i is current column)
    for (int j = 0; j < n; j++) {
        copyPart(A, subMat, 0, j, n);
        // recursively call the determinant on the sub matrix
        det += (A[0][j] * pow(-1.0, (double)j) * determinant(subMat, n-1));
    }

    return det;

} // end determinant

void replaceCol(double A[][DIM], double b[], double out[][DIM], int col) {
    for (int row = 0; row < DIM; row++) {
        for (int j = 0; j < DIM; j++) {
            if (j == col) {
                out[row][j] = b[row];
            }
            else
                out[row][j] = A[row][j];
        }
    }
} // end copyRow