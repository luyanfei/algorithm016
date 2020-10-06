/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (40.34%)
 * Total Accepted:    97K
 * Total Submissions: 240.2K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmin = nums[0], fmax = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int oldfmin = fmin;
            fmin = min(fmin * nums[i], min(fmax * nums[i], nums[i]));
            fmax = max(fmax * nums[i], max(oldfmin * nums[i], nums[i]));
            result = max(result, max(fmin, fmax));
        }
        return result;
    }
};
