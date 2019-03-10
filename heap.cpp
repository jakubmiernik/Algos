#include <iostream>
#include <random>
#include <vector>

#define MAX 100000

template<typename T>
class Heap {
    /*
    * heap start from data[1]
    * Element i:
    * -> parent i/2
    * -> left child 2i
    * -> right child 2i+1
    */
    T data[MAX]; // heap start from 1
    int size = 0;

    inline int parent(int i) { return i / 2; }
    inline int lchild(int i) { return 2 * i; }
    inline int rchild(int i) { return 2 * i + 1; }
    inline void swap(int i, int j) {
        T tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }

    void heapify(int i) { // i - heapify start
        while ((lchild(i) <= size && data[i] > data[lchild(i)]) ||
               (rchild(i) <= size && data[i] > data[rchild(i)])) {
            if (lchild(i) == size || data[rchild(i)] > data[lchild(i)]) {
                swap(i, lchild(i));
                i = lchild(i);
            }
            else {
                swap(i, rchild(i));
                i = rchild(i);
            }
        }
    }

public:
    Heap() {}

    void push(T val) {
        if (size == MAX - 1) {
            std::cout << "heap is full" << std::endl;
        }
        size++;
        int idx = size;
        data[idx] = val;

        while (idx > 1 && data[idx] < data[parent(idx)]) {
            swap(idx, parent(idx));
            idx = parent(idx);
        }
    }

    T pop() {
        if (size == 0) {
            std::cout << "heap is empty" << std::endl;
            return -1;
        }
        T ret = data[1];
        swap(1, size--);
        heapify(1);
        return ret;
    }
};

int main() {
    Heap<int> heap;

    std::vector<int> vec(20);
    for (int& ii : vec) {
        ii = rand() % 100;
    }

    // heap sort
    for (int ii : vec) {
        heap.push(ii);
    }
    for (int& ii : vec) {
        ii = heap.pop();
    }


    for (int ii = 0; ii < 20; ii++) {
        std::cout << vec[ii] << " ";
    }
    std::cout << std::endl;

    return 0;
}