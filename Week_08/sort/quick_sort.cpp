#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int begin, int end) {
    int pivot = begin;
    for (int i = begin; i < end; i++) {
        if (arr[i] < arr[end]) {
            int t = arr[pivot];
            arr[pivot] = arr[i];
            arr[i] = t;
            pivot++;
        }
    }
    int t = arr[pivot];
    arr[pivot] = arr[end];
    arr[end] = t;
    return pivot;
}
void qsort(vector<int>& arr, int begin, int end) {
    if (begin >= end) return;
    int pivot = partition(arr, begin, end);
    qsort(arr, begin, pivot - 1);
    qsort(arr, pivot + 1, end);
}

int main() {
    vector<int> arr{3,5,1,-7,4,9,-6,8,10,4};
    qsort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
