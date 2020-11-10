/*
 * @lc app=leetcode.cn id=493 lang=cpp
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
public:
    int mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) return 0;
        int mid = start + (end - start) / 2;
        int count = mergeSort(nums, start, mid) + mergeSort(nums, mid + 1, end);
        vector<int> merged(end - start + 1);
        int i = start, ci = start, m = 0;
        for (int j = mid + 1; j <= end; j++) {
            while (ci <= mid && nums[ci] / 2.0 <= nums[j]) ci++;
            count += mid - ci + 1;
            while (i <= mid && nums[i] < nums[j]) merged[m++] = nums[i++];
            merged[m++] = nums[j];
        }
        while (i <= mid) merged[m++] = nums[i++];
        for (int k = 0; k < merged.size(); k++) {
            nums[start + k] = merged[k];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
