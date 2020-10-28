/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 删点成林
 *
 * https://leetcode-cn.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (69.72%)
 * Total Accepted:    47K
 * Total Submissions: 64.2K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
 * 
 * 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2,2,1,1,3]
 * 输出：true
 * 解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,2]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 * 
 * 
 */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
        for (int val : arr) {
            um[val]++;
        }
        set<int> uset;
        for (const auto& p : um) {
            if (uset.find(p.second) != uset.end()) {
                return false;
            }
            uset.insert(p.second);
        }
        return true;
    }
};
