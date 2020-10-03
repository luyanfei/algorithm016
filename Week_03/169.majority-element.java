/*
 * @lc app=leetcode.cn id=169 lang=java
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (64.65%)
 * Total Accepted:    217.7K
 * Total Submissions: 336.6K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int major = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (major == nums[i]) {
                count++;
            } else {
                count--;
            }
            if (count < 0) {
                major = nums[i];
                count = 0;
            }
        }
        return major;
    }
}
