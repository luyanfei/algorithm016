/*
 * @lc app=leetcode.cn id=22 lang=cpp
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
class Solution {
public:
    void generate(int left, int right, int n, string& s, vector<string>& result) {
        if (left == n && right == n) {
            result.push_back(s);
            return;
        }
        if (left < n) {
            string s1 = s + '(';
            generate(left + 1, right, n, s1, result);
        }
        if (left > right) {
            string s2 = s + ')';
            generate(left, right + 1, n, s2, result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        generate(0, 0, n, s, result);
        return result;
    }
};
