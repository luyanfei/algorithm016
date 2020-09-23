/*
 * @lc app=leetcode.cn id=16 lang=golang
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
func abs(a int) int {
    if a > 0 {
        return a
    }
    return -a 
}
func threeSumClosest(nums []int, target int) int {
    n := len(nums)
    sort.Ints(nums)
    mindist := math.MaxInt64
    result := 0
    for i := 0; i < n; i++ {
        for j, k := i + 1, n - 1; j < k; {
            three := nums[i] + nums[j] + nums[k]
            dist := abs(three - target)
            if dist < mindist {
                mindist = dist
                result = three
            }
            if three > -target {
                k--
            } else {
                j++
            }
        }
    }
    return result
}
