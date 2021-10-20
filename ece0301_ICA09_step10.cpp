#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "SortableArray.cpp"
using namespace std;

// function prototypes
SortableArray readArray(ifstream&);

int main() {

    // create an instance of a SortableArray with 256 entries
    SortableArray A(256);

    // fill A with random numbers 
    A.fillRandom();

    // open an outfile
    ofstream outfile("ece0301_merge_sort_results.txt");

    // call the write function on A with isSorted set to false
    A.writeText(outfile, false);

    // sort A into B
    A.fullMergeSort();

    // call the write function on A with isSorted set to true
    A.writeText(outfile, true);

    // close files
    outfile.close();

    return 0;
} // end main

SortableArray readArray(ifstream &infile) {
    
    // read first line and make sure it matches header
    string firstLine;
    getline(infile, firstLine);

    if (firstLine.substr(0, 9) != "LENGTH = ") {
        cout << "ERROR! Invalid input file header";
        exit(EXIT_FAILURE);
    }

    // extract length
    int length = stoi(firstLine.substr(9, firstLine.length()));

    // call constructor
    SortableArray array(length);

    // loop to read the number of lines from the file into array
    double *readPtr = array.getArray();
    string line;

    for (int i = 0; i < length; i++) {
        getline(infile, line);
        readPtr[i] = stod(line);
    }

    return array;

} // end readArray