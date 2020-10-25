/*
 * @lc app=leetcode.cn id=647 lang=golang
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
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func countSubstrings(s string) int {
    t := []byte{'$', '#'}
    for _, c := range s {
        t = append(t, byte(c))
        t = append(t, '#')
    }
    t = append(t, '!')
    n := len(t)
    imax, rmax, result := 0, 0, 0
    dp := make([]int, n)
    dp[0] = 1
    for i := 1; i < n - 1 ; i++ {
        if i > rmax {
            dp[i] = 1
        } else {
            dp[i] = min(rmax - i + 1, dp[2 * imax - i])
        }
        for t[i - dp[i]] == t[i + dp[i]] {
            dp[i]++
        }
        if (i + dp[i] - 1 > rmax) {
            rmax = i + dp[i] - 1
            imax = i
        }
        result += dp[i] / 2
    }
    return result
}
