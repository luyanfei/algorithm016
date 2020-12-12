/*
 * @lc app=leetcode.cn id=493 lang=java
 *
 * [493] 翻转对
 *
 * https://leetcode-cn.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (28.74%)
 * Total Accepted:    7.9K
 * Total Submissions: 26.9K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
 * 
 * 你需要返回给定数组中的重要翻转对的数量。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,3,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,4,3,5,1]
 * 输出: 3
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度不会超过50000。
 * 输入数组中的所有数字都在32位整数的表示范围内。
 * 
 * 
 */
class Solution {
    private int merge(int[] nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int count = merge(nums, left, mid) + merge(nums, mid + 1, right);
        int[] arr = new int[right - left + 1];
        int k = 0, i = left, c = left, j = mid + 1;
        for (; j <= right; j++) {
            while (nums[c] / 2.0 <= nums[j] && c <= mid) c++;
            count += mid - c + 1;
            while (nums[i] < nums[j] && i <= mid) arr[k++] = nums[i++];
            arr[k++] = nums[j];
        }
        while (i <= mid) arr[k++] = nums[i++];
        for (int t = 0; t < arr.length; t++) {
            nums[left + t] = arr[t];
        }
        return count;
    }
    public int reversePairs(int[] nums) {
        return merge(nums, 0, nums.length - 1);
    }
}
