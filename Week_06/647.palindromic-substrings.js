/*
 * @lc app=leetcode.cn id=647 lang=javascript
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (64.52%)
 * Total Accepted:    67.7K
 * Total Submissions: 105K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 输入："aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串长度不会超过 1000 。
 * 
 * 
 */
/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let t = '$#'
    for (let c of s) {
        t += c + '#'
    }
    t += '!'
    let dp = new Array(t.length)
    dp.fill(1)
    let maxpos = 0, center = 0, count = 0
    for (let i = 1; i < t.length - 1; i++) {
        if (i < maxpos) {
            let left = 2 * center - i
            dp[i] = Math.min(maxpos - i, dp[left])
        }
        while (t[i - dp[i]] === t[i + dp[i]])
            dp[i]++
        if (i + dp[i] - 1 > maxpos) {
            maxpos = i + dp[i] - 1
            center = i
        }
        count += Math.floor(dp[i] / 2)
    }
    return count
};
