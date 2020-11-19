/*
 * @lc app=leetcode.cn id=32 lang=java
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
class Solution {
    public int longestValidParentheses(String s) {
        if (s.length() < 2) return 0;
        int maxlen = 0;
        int[] dp = new int[s.length()];
        if (s.substring(0, 2).equals("()")) {
            dp[1] = 2;
            maxlen = 2;
        }
        for (int i = 2; i < s.length(); i++) {
            String last2 = s.substring(i - 1, i + 1);
            if (last2.equals("()")) {
                dp[i] = dp[i - 2] + 2;
            } else if (last2.equals("))")) {
                int idx = i - 1 - dp[i - 1];
                if (idx > 0 && s.charAt(idx) == '(') {
                    dp[i] = dp[i - 1] + dp[idx - 1] + 2;
                } else if (idx == 0 && s.charAt(idx) == '(') {
                    dp[i] = dp[i - 1] + 2;
                }
            }
            maxlen = Math.max(maxlen, dp[i]);
        }
        return maxlen;
    }
}
