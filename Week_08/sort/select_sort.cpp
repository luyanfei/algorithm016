#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = t;
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
