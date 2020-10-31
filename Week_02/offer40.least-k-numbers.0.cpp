class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> q;
        for (int i = 0; i < arr.size(); i++) {
            if (i < k) {
                q.push(arr[i]);
            } else if (!q.empty() && arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.emplace_back(q.top());
            q.pop();
        }
        return result;
    }
};
