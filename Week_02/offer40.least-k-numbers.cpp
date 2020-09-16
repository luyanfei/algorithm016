class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        vector<int> result(k, 0);
        if (k == 0) {
            return result;
        }
        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top();
            pq.pop();
        }
        return result;
    }
};
