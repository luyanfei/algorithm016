#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr) {
    for (int j = 1; j < arr.size(); j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

int main() {
    vector<int> arr{8, 4, 3, 7, 2, 1, 9};
    sort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
