class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            int minarea = height[i] > height[j] ? height[j--] : height[i++];
            int area = minarea * (j-i+1);
            if (area > max)
                max = area;
        }
        return max;
    }
};
