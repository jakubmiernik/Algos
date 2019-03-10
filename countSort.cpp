#include <iostream>
#include <random>

#define MAX 2000000

// helper tab to collect occurence of each number
// countTab need to be init with 0
static int countTab[MAX];

// counting sort algoritm - count number of occurence 
// of each number from 0 to maxVal
void countSort(int* in, int* out, int size, int maxVal) {
    if (maxVal > MAX) {
        std::cout << "Too big max value" << std::endl;
        return;
    }
    for (int ii = 0; ii < maxVal; ii++) 
        countTab[ii] = 0;

    for(int ii = 0; ii < size; ii++)
        countTab[in[ii]]++;
    for (int jj = 0, ii = 0; ii < maxVal; ii++) {
        while(countTab[ii]) {
            out[jj] = ii;
            countTab[ii]--;
            jj++;
        }
    }
}

void stableCountSort(int* in, int* out, int size, int maxVal) {
        if (maxVal > MAX) {
        std::cout << "Too big max value" << std::endl;
        return;
    }
    for (int ii = 0; ii < maxVal; ii++) 
        countTab[ii] = 0;

    for (int ii = 0; ii < size; ii++)
        countTab[in[ii]]++;
    for (int ii = 1; ii < maxVal; ii++)
        countTab[ii] += countTab[ii-1];
    for (int ii = size - 1; ii >=0; ii--){
        out[--countTab[in[ii]]] = in[ii];
    }
}

int main() {
    int maxVal = 200;
    const int tabSize = 100;
    int tab[tabSize];
    int tabSorted[tabSize];

    std::cout << "Random tab:" << std::endl;
    for (auto& ii : tab) {
        ii = rand() % maxVal;
        std::cout << ii << " ";
    }
    std::cout << std::endl;

    // countSort(tab, tabSorted, tabSize, maxVal);
    stableCountSort(tab, tabSorted, tabSize, maxVal);

    std::cout << "Sorted tab:" << std::endl;
    for (auto ii : tabSorted) {
        std::cout << ii << " ";
    }
    std::cout << std::endl;
    return 0;
}