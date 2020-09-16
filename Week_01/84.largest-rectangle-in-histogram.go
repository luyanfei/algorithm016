/*
 * @lc app=leetcode.cn id=84 lang=golang
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (41.65%)
 * Total Accepted:    86.8K
 * Total Submissions: 208.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */
func largestRectangleArea(heights []int) int {
    n := len(heights)
    stack := make([]int, 0, n)
    left := make([]int, n, n)
    right := make([]int, n, n)
    for i := 0; i < n; i++ {
        right[i] = n
    }
    maxarea := 0
    for i := 0; i < n; i++ {
        for len(stack) > 0 && heights[i] <= heights[stack[len(stack) - 1]] {
            top := stack[len(stack) - 1]
            right[top] = i
            stack = stack[:len(stack) - 1]
        }
        if len(stack) > 0 {
            left[i] = stack[len(stack) - 1]
        } else {
            left[i] = -1
        }
        stack = append(stack, i)
    }
    for i := 0; i < n; i++ {
        area := (right[i] - left[i] - 1) * heights[i]
        if area > maxarea {
            maxarea = area
        }
    }
    return maxarea
}
