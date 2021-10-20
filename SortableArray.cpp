#include "SortableArray.h"

void SortableArray::mergeSort(double *pre, double *post, unsigned int blackIdx, unsigned int greyIdx, unsigned int blueIdx) {
    // initialize pointers
    double *black = &pre[blackIdx], *grey = &pre[greyIdx], *red = grey, *blue = &pre[blueIdx], *green = &post[blackIdx];

    // loop through first subarray to the start of the second subarray
    while (black < red && grey < blue) {

        // if black value is less than grey value, insert black
        if (*black < *grey) {
            *green = *black;
            black++;
        }
        // if grey value is less than black value, insert grey
        else {
            *green = *grey;
            grey++;
        }

        // increment green
        green++;
    }

    // add rest of first subarray if second runs out first
    while (black < red) {
        *green = *black;
        green++;
        black++;
    }

    // add rest of second subarray if first runs out first
    while (grey < blue) {
        *green = *grey;
        green++;
        grey++;
    }
}

// define recursive splitting method
void SortableArray::split(double *pre, double *post, unsigned int start, unsigned int end) {
    // base case: if end is one more than start, return
    if (end - start == 1) return;

    // define the mid as the average of the two int parameters
    unsigned int mid = start + (end - start) / 2;

    // recursively call the split function on the first half of the array
    split(post, pre, start, mid);

    // recursively call the split function on the second half of the array
    split(post, pre, mid, end);

    // call the merge function on split arrays
    mergeSort(pre, post, start, mid, end);
}

// define the default constructor
SortableArray::SortableArray() {
    // assign the data members
    numElems = 10;
    array = new double[numElems];

    // call the fillZeros function
    fillZeros();
}

// define a second constructor
SortableArray::SortableArray(unsigned int n) {
    // assign the data members
    numElems = n;
    array = new double[numElems];

    // call the fillZeros function
    fillZeros();
}

// define the destructor
SortableArray::~SortableArray() {
    delete [] array;
}

// define getArray
double* SortableArray::getArray() {
    return array;
}

// define getNumElems
unsigned int SortableArray::getNumElems() {
    return numElems;
}

// define fillZeros
void SortableArray::fillZeros() {
    for (int i = 0; i < numElems; i++)
        array[i] = 0;
}

// define writeText
void SortableArray::writeText(ofstream& outfile, bool isSorted) {
    // output if not sorted, or in the other case, sorted
    if (!isSorted) {
        // print headers
        outfile << "ECE 0301 - Sorting Arrays" << endl;
        outfile << "Unsorted Array:" << endl;
    }
    else 
        outfile << "Sorted Array:" << endl;

    // write the array to file
    for (int i = 0; i < numElems; i++)
        outfile << array[i] << endl;
}

// does the full merge sort algorithm
void SortableArray::fullMergeSort() {
    // define a pointer to the array
    double *currArr = getArray();

    // define an object for the working array
    SortableArray workingArray(getNumElems());

    // define a pointer to the working array
    double *workingArr = workingArray.getArray();

    // copy the data from currArr to workingArray
    for (int i = 0; i < getNumElems(); i++)
        workingArr[i] = currArr[i];

    // call the split function
    split(workingArr, currArr, 0, getNumElems());
}

void SortableArray::fillRandom() {
    // create a seed for the random ints using time(0)
    unsigned int seed = time(0);

    // seed the generator
    srand(seed);

    double randNum;
    // fill the array with random numbers
    for (int i = 0; i < numElems; i++) {
        // cast randNum to a double
        randNum = static_cast<double>(rand()) / RAND_MAX;

        // convert randNum to between -1 and +1
        randNum = 2*randNum - 1;

        // assign the random number to index i
        array[i] = randNum;
    }
}