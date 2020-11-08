## 插入排序
```
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
```
## 选择排序
```
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
```
## 冒泡排序
```
void sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1 -i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
```
## 快速排序
```
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
```
## 归并排序
```
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1, 0);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }
}
void msort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    msort(arr, left, mid);
    msort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
```
## 学习总结
训练营后期的难题较多，每做一次都耗费很长时间，本周的精力主要用在做旧题上，根据原先安排的进度，有时一天要做十来道旧题，做新题的进度有些滞后。

位运算的操作与补码的知识关联密切，尤其是下面两个运算：
```
x & (-x)
x & (x - 1)
```
计算补码有两种方式，第一种很多人知道，就是全部取反后再加1。另一种则是二进制的最低位的1保持不变，在它之前的位取反。这种方式在查阅资料后，在本周的练习中得到了巩固。

知道位运算是怎么回事，与使用位运算，两者之间还是有距离的，位运算的题虽在leetcode上标识为简单和中级，但对我来说，它们比有些标记为困难的题还要难一些。只有在做完第二遍后，才隐约有些掌控的感觉。

