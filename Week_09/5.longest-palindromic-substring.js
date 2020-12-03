/*
 * @lc app=leetcode.cn id=5 lang=javascript
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.29%)
 * Total Accepted:    418.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s.length === 0) return ''
    let dp = new Array(s.length)
    for (let i = 0; i < s.length; i++) {
        dp[i] = new Array(s.length)
        dp[i].fill(false)
    }
    let item = ''
    for (let i = s.length - 1; i >= 0; i--) {
        for (let j = i; j < s.length; j++) {
            if (s[i] === s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                dp[i][j] = true
            }
            if (dp[i][j] && j - i + 1 > item.length) {
                item = s.substring(i, j + 1)
            }
        }
    }
    return item
};
