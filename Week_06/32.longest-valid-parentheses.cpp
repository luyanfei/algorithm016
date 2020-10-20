/*
 * @lc app=leetcode.cn id=32 lang=cpp
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
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len <= 1) {
            return 0;
        }
        vector<int> dp(len, 0);
        dp[1] = s[0] == '(' && s[1] == ')' ? 2 : 0;
        for (int i = 2; i < len; i++) {
            if (s[i - 1] == '(' && s[i] == ')') {
                dp[i] = dp[i - 2] + 2;
            }
            if (i - dp[i - 1] > 0 && s[i - 1] == ')' && s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {
                if (i - dp[i - 1] >= 2)
                    dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                else
                    dp[i] = dp[i - 1] + 2;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
