#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SortableArray {
    private:
        double *array;
        unsigned int numElems;
        void mergeSort(double *, double *, unsigned int, unsigned int, unsigned int);
        void split(double *, double *, unsigned int, unsigned int);
    public:
        SortableArray();
        SortableArray(unsigned int);
        ~SortableArray();
        double* getArray();
        unsigned int getNumElems();
        void fillZeros();
        void writeText(ofstream&, bool);
        void fullMergeSort();
        void fillRandom();
}; // end SortableArray

#endif