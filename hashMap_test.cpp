#include <iostream>
#include <random>

#include "structs/hashMap.hpp"
#include <map>

int random(int from, int to) {
	int width = to - from;
	int rNumber = rand() % width;
	return rNumber + from;
}

int main() {
	HashMap<int, int, 1234> myMap;
	std::map<int, int> stdMap;

	for (int tt = 0; tt < 10000; tt++) {
		int command = random(0, 3);

		switch (command)
		{
		case 0: // insert
		{
			int key = random(-0xFFF, 0xFFF);
			int val = random(-0xFFF, 0xFFF);
			myMap.insert_or_assign(key, val);
			stdMap.insert_or_assign(key, val);
			break;
		}
		case 1: // get
		{
			int key = random(-0xFFF, 0xFFF);
			auto stdMapIter = stdMap.find(key);
			if (myMap.contains(key)) {
				int myMapVal = myMap.get(key);
				if (myMapVal == stdMapIter->second)
					break;
				else
					throw;
			}
			else {
				if (stdMapIter == stdMap.end())
					break;
				else
					throw;
			}
		}
		case 2: // remove
		{

			break;
		}
		default:
			break;
		}
	}
	return 0;
}