/*
 * @lc app=leetcode.cn id=5 lang=java
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
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        String item = s.substring(s.length() - 1);
        dp[n - 1][n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = j > i + 1 ? dp[i + 1][j - 1] : 1;
                }
                if (j - i + 1 > item.length() && dp[i][j] == 1) {
                    item = s.substring(i, j + 1);
                }
            }
        }
        return item;
    }
}
