/*
 * @lc app=leetcode.cn id=22 lang=golang
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.23%)
 * Total Accepted:    180.8K
 * Total Submissions: 237.1K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */
func generateParenthesis(n int) []string {
    result := []string{}
    item := ""
    var backtrack func(left, right int)
    backtrack = func(left, right int) {
        if left == n && right == n {
            result = append(result, item)
            return
        }
        if left < n {
            item += "("
            backtrack(left + 1, right)
            item = item[:len(item) - 1]
        }
        if right < left {
            item += ")"
            backtrack(left, right + 1)
            item = item[:len(item) - 1]
        }
    }
    backtrack(0, 0)
    return result
}
