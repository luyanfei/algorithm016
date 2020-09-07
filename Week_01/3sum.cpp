#include <algorithm>
#include <vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                if (nums[j] + nums[k] == -nums[i]) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j+1] == nums[j]) j++;
                    while (j < k && nums[k-1] == nums[k]) k--;
                    j++;
                    k--;
                } else if (nums[j] + nums[k] > -nums[i]) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};
