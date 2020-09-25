/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.95%)
 * Total Accepted:    198.8K
 * Total Submissions: 258.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
class Solution {
    vector<vector<int>> result;
    void build(vector<int>& nums, int first) {
        int n = nums.size();
        if (first == n) {
            result.emplace_back(nums);
            return;
        }
        for (int i = first; i < n; ++i) {
            swap(nums[i], nums[first]);
            build(nums, first + 1);
            swap(nums[i], nums[first]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        build(nums, 0);
        return result;
    }
};
