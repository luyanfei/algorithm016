/*
 * @lc app=leetcode.cn id=22 lang=java
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
    private List<String> result = new ArrayList<>();
    private StringBuilder item = new StringBuilder();
    private void generate(int n, int left, int right) {
        if (left > n || right > n) return;
        if (left == n && right == n) {
            result.add(item.toString());
            return;
        }
        if (left < n) {
            item.append('(');
            generate(n, left + 1, right);
            item.deleteCharAt(item.length() - 1);
        }
        if (right < left) {
            item.append(')');
            generate(n, left, right + 1);
            item.deleteCharAt(item.length() - 1);
        }
    }
    public List<String> generateParenthesis(int n) {
        generate(n, 0, 0);
        return result;
    }
}
