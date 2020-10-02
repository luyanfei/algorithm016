/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.88%)
 * Total Accepted:    209.9K
 * Total Submissions: 540.1K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
