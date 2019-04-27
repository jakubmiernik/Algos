#include "vector.hpp"

template<typename T>
class queue {
	vector<T> inStack;
	vector<T> outStack;
	void reballance() {
		if (outStack.size() == 0) {
			while (inStack.size() > 0) {
				outStack.push_back(inStack.back());
				inStack.pop_back();
			}
		}
	}
public:
	void push(T val) {
		inStack.push_back(val);
	}
	T front() {
		reballance();
		return outStack.back();
	}
	void pop() {
		reballance();
		outStack.pop_back();
	}
	bool empty() {
		return inStack.size() + outStack.size() == 0;
	}
};