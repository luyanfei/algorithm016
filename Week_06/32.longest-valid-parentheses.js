/*
 * @lc app=leetcode.cn id=32 lang=javascript
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (33.94%)
 * Total Accepted:    107.6K
 * Total Submissions: 316.9K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    if (s.length < 2) return 0
    let dp = new Array(s.length)
    dp.fill(0)
    if (s.substring(0, 2) === '()') dp[1] = 2
    for (let i = 2; i < s.length; i++) {
        if (s.substring(i - 1, i + 1) === '()') {
            dp[i] = dp[i - 2] + 2
        } 
        if (s.substring(i - 1, i + 1) === '))' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] === '(') {
            if (i - dp[i - 1] - 2 >= 0) {
                dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
            } else {
                dp[i] = dp[i - 1] + 2
            }
        }
    }
    return dp.reduce((acc, v) => Math.max(acc, v), 0)
};
