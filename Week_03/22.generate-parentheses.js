/*
 * @lc app=leetcode.cn id=22 lang=javascript
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
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let item = [], result = []
    let build = function(left, right) {
        if (left > n || right > n) {
            return
        }
        if (left === n && right === n) {
            result.push(item.join(''))
            return
        }
        if (left < n) {
            item.push('(')
            build(left + 1, right)
            item.pop()
        }
        if (right < left) {
            item.push(')')
            build(left, right + 1)
            item.pop()
        }
    }
    build(0, 0)
    return result
};
