/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.83%)
 * Total Accepted:    152.3K
 * Total Submissions: 332.4K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */
#include <limits>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int m = std::numeric_limits<int>::max();
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                int dist = abs(sum - target);
                if (dist < m) {
                    m = dist;
                    result = sum;
                }
                if (sum >= target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};
