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
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        vector<vector<int>> result{empty};
        for (int num : nums) {
            vector<vector<int>> tmp;
            for (auto item : result) {
                item.push_back(num);
                tmp.push_back(item);
            }
            for (auto item : tmp) {
                result.push_back(item);
            }
        }
        return result;
    }
};
