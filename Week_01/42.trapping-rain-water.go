/*
 * @lc app=leetcode.cn id=42 lang=golang
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.55%)
 * Total Accepted:    146.4K
 * Total Submissions: 278.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */
//package main
type stack []int
func newStack(k int) stack {
    return make([]int, 0, k)
}
func (s stack) push(val int) stack {
    return append(s, val)
}
func (s stack) pop() stack {
    if len(s) == 0 {
        panic("Nothing to pop.")
    }
    return s[:len(s) - 1]
}
func (s stack) top() int {
    return s[len(s) - 1]
}
func (s stack) empty() bool {
    return len(s) == 0
}
func min (a, b int) int {
    if a < b {
        return a
    }
    return b
}
func trap(height []int) int {
    result := 0
    s := newStack(len(height))
    for i, v := range height {
        for !s.empty() && v > height[s.top()] {
            top := s.top()
            s = s.pop()
            if !s.empty() {
                diff := min(v, height[s.top()]) - height[top]
                result += diff * (i - s.top() - 1)
            }
        }
        s = s.push(i)
    }
    return result
}

//func main() {
    //s := newStack(10)
    //s = s.push(2)
    //s = s.push(3)
    //s = s.pop()
//
//}
