template<class T>
class vector {
    T* buffer;
    int bufferSize;
    int vectorSize;
    void realloc() {
        if (buffer == nullptr)
            bufferSize = 4;
        else
            bufferSize *= 2;

        T* newBuffer = new T[bufferSize];
        for (int ii = 0; ii < vectorSize; ii++)
            newBuffer[ii] = buffer[ii];
        delete[] buffer;
        buffer = newBuffer;
    }
public:
    vector() {
        buffer = nullptr;
        vectorSize = 0;
        bufferSize = 0;
    }
    ~vector() {
        delete[] buffer;
    }
    void push_back(T val) {
        if (vectorSize == bufferSize)
            realloc();
        buffer[vectorSize++] = val;
    }
    void pop_back() {
        vectorSize--;
    }
    T back() {
        return buffer[vectorSize - 1];
    }
    T &operator[](int ii) {
        return buffer[ii];
    }
    int size() {
        return vectorSize;
    }
	void clear() {
		vectorSize = 0;
	}
};