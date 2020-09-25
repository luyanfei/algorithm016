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
    vector<vector<int>> result;
    void permute(vector<int>& nums, vector<int>& perm, vector<bool>& visited, int first) {
        int n = nums.size();
        if (first == n) {
            result.emplace_back(perm);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue;
            }
            perm.push_back(nums[i]);
            visited[i] = true;
            permute(nums, perm, visited, first + 1);
            visited[i] = false;
            perm.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> perm;
        vector<bool> visited(nums.size(), false);
        permute(nums, perm, visited, 0);
        return result;
    }
};
