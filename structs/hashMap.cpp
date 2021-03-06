#include <random>
#include <iostream>

#define MAX 100000
#define MAP_SIZE 100000

struct Data {
	int val;
	int key;
	int next;
};

Data data[MAX];

class HashMap {
	// map start at 1
	int hashMap[MAP_SIZE]{ 0 };

	inline int hash(int key) { return key % MAP_SIZE; }

public:
	void put(int idx) {
		int h = hash(data[idx].key);
		data[h].next = hashMap[h];
		hashMap[h] = idx;
	}

	int get(int key) {
		int h = hash(key);
		int idx = hashMap[h];
		while (idx != 0 && data[idx].key != key)
			idx = data[idx].next;
		return idx;
	}

	void remove(int key) {
		data[get(key)].key = -1;
	}
};

void fillData(int n) {
	for (int ii = 1; ii <= n; ii++) {
		Data d{ ii, rand(), 0};
		data[ii] = d;
	}
}

HashMap hashMap;

int main() {

	int testSize = 10000;
	fillData(testSize);

	// put data to hash map
	for (int ii = 0; ii < testSize; ii++) {
		hashMap.put(ii);
	}


	for (int ii = 0; ii < 200; ii++) {
		int inIdx = rand() % testSize;
		int rKey = data[inIdx].key;
		int idx = hashMap.get(rKey);
		_ASSERT(idx != 0);
		std::cout << idx << std::endl;
	}

	return 0;
}
