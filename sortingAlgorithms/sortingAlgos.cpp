#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cassert>
#include <chrono>

// ************ HELPERS ******************//
template <typename T>
std::vector<T> generateData(size_t size, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
    static std::uniform_int_distribution<T> distribution(min, max);
    static std::default_random_engine generator;

    std::vector<T> data(size);
    std::generate(data.begin(), data.end(), []()
                  { return distribution(generator); });
    return data;
}

template <typename T>
void printData(const std::vector<T> &data)
{
    for (auto &val : data)
    {
        std::cout << val << "\n";
    }
}

template <typename T>
void testSort(const std::vector<T> &data)
{
    for (int ii = 1; ii < data.size(); ii++)
    {
        assert(data[ii] >= data[ii - 1]);
    }
}

// ************ QUICK SORT ******************//
template <typename T>
void swap(std::vector<T> &vec, int ii, int jj)
{
    T tmp = vec[ii];
    vec[ii] = vec[jj];
    vec[jj] = tmp;
}

template <typename T>
void quickSort(std::vector<T> &input, int left, int right)
{
    int pivot = input[(right + left) / 2];
    int i = left;
    int j = right;

    while (1)
    {
        while (input[i] < pivot)
            i++;
        while (input[j] > pivot)
            j--;

        if (j < i)
        {
            break;
        }

        swap(input, i, j);
        i++;
        j--;
    }

    if (j > left)
        quickSort(input, left, j);
    if (i < right)
        quickSort(input, i, right);
}

// ************ MERGE SORT ******************//
template <typename T>
void merge(std::vector<T> &input, int start, int mid, int end)
{
    int sizeL = mid - start + 1;
    int sizeR = end - mid;

    std::vector<T> left(input.begin() + start, input.begin() + mid + 1);
    std::vector<T> right(input.begin() + mid + 1, input.begin() + end + 1);
    assert(left.size() == sizeL);
    assert(right.size() == sizeR);

    int l_idx = 0;
    int r_idx = 0;
    int ii = start;

    while (l_idx < sizeL && r_idx < sizeR)
    {
        if (left[l_idx] <= right[r_idx])
        {
            input[ii] = left[l_idx];
            l_idx++;
        }
        else
        {
            input[ii] = right[r_idx];
            r_idx++;
        }
        ii++;
    }

    while (l_idx < sizeL)
    {
        input[ii] = left[l_idx];
        l_idx++;
        ii++;
    }

    while (r_idx < sizeR)
    {
        input[ii] = right[r_idx];
        r_idx++;
        ii++;
    }
    assert(ii == end + 1);
}

template <typename T>
void mergeSort(std::vector<T> &input, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    auto mid = start + (end - start) / 2;
    mergeSort(input, start, mid);
    mergeSort(input, mid + 1, end);
    merge(input, start, mid, end);
}

// ************ HEAP SORT ******************//
constexpr int leftChild(int n) { return 2 * n + 1; }
constexpr int rightChild(int n) { return 2 * n + 2; }

template <typename T>
void heapify(std::vector<T> &input, int size, int idx)
{
    int max_idx = idx;
    int left = leftChild(idx);
    int right = rightChild(idx);
    if (left < size && input[left] > input[max_idx])
    {
        max_idx = left;
    }
    if (right < size && input[right] > input[max_idx])
    {
        max_idx = right;
    }

    if (max_idx != idx)
    {
        swap(input, max_idx, idx);
        heapify(input, size, max_idx);
    }
}

template <typename T>
void buildHeap(std::vector<T> &input, int size)
{
    for (int ii = size / 2 - 1; ii >= 0; ii--)
    {
        heapify(input, size, ii);
    }
}

template <typename T>
void heapSort(std::vector<T> &input)
{
    buildHeap(input, input.size());

    for (int ii = 0; ii < input.size(); ii++)
    {
        swap(input, 0, input.size() - 1 - ii);
        heapify(input, input.size() - 1 - ii, 0);
    }
}

// ************ MAIN ******************//

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;

int main()
{
    auto data = generateData<int>(1000);
    auto data2 = data;
    auto data3 = data;

    auto t1 = high_resolution_clock::now();
    mergeSort(data, 0, data.size() - 1);
    auto t2 = high_resolution_clock::now();

    auto t3 = high_resolution_clock::now();
    quickSort(data2, 0, data2.size() - 1);
    auto t4 = high_resolution_clock::now();

    auto t5 = high_resolution_clock::now();
    heapSort(data3);
    auto t6 = high_resolution_clock::now();

    std::cout << "MergeSort time " << duration_cast<microseconds>(t2 - t1).count() << "us\n";
    std::cout << "qSort time " << duration_cast<microseconds>(t4 - t3).count() << "us\n";
    std::cout << "heapSort time " << duration_cast<microseconds>(t6 - t5).count() << "us\n";

    testSort(data);
    testSort(data2);
    testSort(data3);
    // printData(data3);
}
