template<typename T, bool(*OP)(T, T)>
class Heap {
    /*
    * heap start from data[1]
    * heap end on data[heapSize]
    * data[0] is invalid element
    * Element i:
    * -> parent i/2
    * -> left child 2i
    * -> right child 2i+1
    */
    vector<T> data;
    int heapSize;
    int parent(int ii) { return ii / 2; }
    int left(int ii) { return 2 * ii; }
    int right(int ii) { return 2 * ii + 1; }
    bool isFirstBetter(T a, T b) {
        return OP(a, b);
    }
    void swap(int ii, int jj) {
        T tmp = data[ii];
        data[ii] = data[jj];
        data[jj] = tmp;
    }
    void heapUp(int ii) {
        while (ii > 1 && isFirstBetter(data[ii], data[parent(ii)])) {
            swap(ii, parent(ii));
            ii = parent(ii);
        }
    }
    void heapDown(int ii) {
        while ((left(ii) <= heapSize && isFirstBetter(data[left(ii)], data[ii])) ||
            (right(ii) <= heapSize && isFirstBetter(data[right(ii)], data[ii]))) {
            if (left(ii) == heapSize || isFirstBetter(data[left(ii)], data[right(ii)])) {
                swap(ii, left(ii));
                ii = left(ii);
            }
            else {
                swap(ii, right(ii));
                ii = right(ii);
            }
        }
    }
public:
    Heap() {
        data.push_back(-1); // invali element on pos data[0]
        heapSize = 0;
    }
    void push(T val) {
        heapSize++;
        data.push_back(val);
        heapUp(heapSize);
    }
    void pop() {
        swap(1, heapSize);
        data.pop_back();
        heapSize--;
        heapDown(1);
    }
    T top() {
        return data[1];
    }
    int size() { return heapSize; }

    void removeByIdx(int ii) {
        swap(ii, heapSize);
        data.pop_back();
        heapSize--;

        if (ii <= heapSize) {
            heapDown(ii);
            heapUp(ii);
        }
    }
};