class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[s.top()] < height[i]) {
                //用到栈顶部的两个元素，先保存顶部元素
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    break;
                }
                int distance = i - s.top() - 1;
                int delta = min(height[s.top()], height[i]) - height[top]; 
                result += delta * distance;
            }
            s.push(i);
        }
        return result;
    }
};
