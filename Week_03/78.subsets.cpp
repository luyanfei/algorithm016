/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.03%)
 * Total Accepted:    156K
 * Total Submissions: 197.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
    vector<vector<int>> result;
    vector<int> subset;
    void build(int first, vector<int>& nums) {
        if (first == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[first]);
        build(first + 1, nums);
        subset.pop_back();
        build(first + 1, nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        build(0, nums);
        return result;
    }
};
