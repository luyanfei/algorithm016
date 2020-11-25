/*
 * @lc app=leetcode.cn id=5 lang=golang
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
func longestPalindrome(s string) string {
    n := len(s)
    if n == 0 {
        return ""
    }
    dp := make([][]bool, n)
    for i := 0; i < n; i++ {
        dp[i] = make([]bool, n)
    }
    item := ""
    for i := n - 1; i >= 0; i-- {
        for j := i; j < n; j++ {
            if i == j {
                dp[i][j] = true
            } else if j == i + 1 {
                dp[i][j] = s[i] == s[j]
            } else {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1]
            }
            if dp[i][j] && j - i + 1 > len(item) {
                item = s[i:j + 1]
            }
        }
    }
    return item
}
