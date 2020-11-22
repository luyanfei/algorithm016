/*
 * @lc app=leetcode.cn id=493 lang=golang
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
func reversePairs(nums []int) int {
    var merge func(left, right int) int
    merge = func(left, right int) int {
        if left >= right {
            return 0
        }
        count := 0
        mid := left + (right - left) / 2
        count += merge(left, mid)
        count += merge(mid + 1, right)
        arr := make([]int, right - left + 1, right - left + 1)
        k, i, ci := 0, left, left
        for j := mid + 1; j <= right; j++ {
            for ci <= mid && float64(nums[ci]) / 2.0 <= float64(nums[j]) {
                ci++
            }
            count += mid - ci + 1
            for i <= mid && nums[i] < nums[j] {
                arr[k] = nums[i]
                k++
                i++
            }
            arr[k] = nums[j]
            k++
        }
        for i <= mid {
            arr[k] = nums[i]
            i++
            k++
        }
        for t := 0; t < len(arr); t++ {
            nums[left + t] = arr[t]
        }
        return count
    }
    if len(nums) == 0 {
        return 0
    }
    return merge(0, len(nums) - 1)
}
