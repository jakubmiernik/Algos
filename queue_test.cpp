#include <iostream>
#include <random>
#include "structs/vector.hpp"
#include "structs/queue.hpp"

bool min(int a, int b) { return a < b; }

int main() {
    queue<int> queue;

    vector<int> vec;
	int numValue = 20;
	for (int ii = 0; ii < numValue; ii++)
		vec.push_back(rand() % 200);

    // heap sort
	for (int ii = 0; ii < numValue; ii++)
        queue.push(vec[ii]);

	for (int ii = 0; ii < 20; ii++) {
		std::cout << vec[ii] << " ";
	}
	std::cout << std::endl;

	vec.clear();

	for (int ii = 0; ii < numValue; ii++) {
        vec[ii] = queue.front();
		queue.pop();
    }

    for (int ii = 0; ii < 20; ii++) {
        std::cout << vec[ii] << " ";
    }
    std::cout << std::endl;

    return 0;
}