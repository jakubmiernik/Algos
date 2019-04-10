#include <iostream>
#include <random>
#include "vector.hpp"
#include "heap.hpp"

bool min(int a, int b) { return a < b; }

//int main() {
//    Heap<int, min> heap;
//
//    vector<int> vec;
//	int numValue = 20;
//	for (int ii = 0; ii < numValue; ii++)
//		vec.push_back(rand() % 200);
//
//    // heap sort
//	for (int ii = 0; ii < numValue; ii++)
//        heap.push(vec[ii]);
//
//	for (int ii = 0; ii < numValue; ii++) {
//        vec[ii] = heap.top();
//		heap.pop();
//    }
//
//    for (int ii = 0; ii < 20; ii++) {
//        std::cout << vec[ii] << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}