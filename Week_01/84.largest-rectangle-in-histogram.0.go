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
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func largestRectangleArea(heights []int) int {
    n := len(heights)
    if n == 0 {
        return 0
    }
    left, right := make([]int, n, n), make([]int, n, n)
    for i := 0; i < n; i++ {
        right[i] = n
    }
    left[0] = -1
    stack := []int{0}
    for i := 1; i < n; i++ {
        for len(stack) > 0 && heights[i] < heights[stack[len(stack) - 1]] {
            right[stack[len(stack) - 1]] = i
            stack = stack[:len(stack) - 1]
        }
        if len(stack) == 0 {
            left[i] = -1
        } else {
            left[i] = stack[len(stack) - 1]
        }
        stack = append(stack, i)
    }
    maxarea := 0
    for i := 0; i < n; i++ {
        area := heights[i] * (right[i] - left[i] - 1)
        maxarea = max(maxarea, area)
    }
    return maxarea
}
