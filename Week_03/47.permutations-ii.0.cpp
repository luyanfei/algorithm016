/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (61.93%)
 * Total Accepted:    111.4K
 * Total Submissions: 179.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> item;
        function<void(int)> build = [&] (int start) {
            if (start == n) {
                result.push_back(item);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])) {
                    continue;
                }
                visited[i] = true;
                item.push_back(nums[i]);
                build(start + 1);
                item.pop_back();
                visited[i] = false;
            }
        };
        build(0);
        return result;
    }
};
