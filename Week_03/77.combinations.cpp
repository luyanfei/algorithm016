/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (75.72%)
 * Total Accepted:    105.9K
 * Total Submissions: 139.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
class Solution {
    void build(int n, int current, vector<int> v, int k, vector<vector<int>>& result) {
        if (v.size() == k) {
            result.push_back(v);
            return;
        }
        if (current > n || k - v.size() > n - current + 1) {
            return;
        }
        build(n, current + 1, v, k, result);
        v.push_back(current);
        build(n, current + 1, v, k, result);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> v;
        build(n, 1, v, k, result);
        return result;
    }
};
