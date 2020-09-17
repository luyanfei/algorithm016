/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 3Sum
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.35%)
 * Total Accepted:    319.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
//package main
//import "fmt"
//import "sort"
//
func threeSum(nums []int) [][]int {
    sort.IntSlice(nums).Sort()
    var result [][]int
    for i := 0; i < len(nums) - 2; i++ {
        if i != 0 && nums[i] == nums[i - 1] {
            continue
        }
        j := i + 1
        k := len(nums) - 1
        for j < k {
            if j != i + 1 && nums[j] == nums[j - 1] {
                j++
                continue
            }
            if nums[j] + nums[k] == -nums[i] {
                result = append(result, []int{nums[i], nums[j], nums[k]})
                j++
                k--
            } else if nums[j] + nums[k] > -nums[i] {
                k--
            } else {
                j++
            }
        }
    }
    return result
}

//func main() {
    //var a = []int{-1,0,1,2,-1,-4}
    //threeSum(a)
//}
