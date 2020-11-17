/*
 * @lc app=leetcode.cn id=647 lang=java
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
class Solution {
    public int countSubstrings(String s) {
        if (s.length() == 0) return 0;
        StringBuilder builder = new StringBuilder("$#");
        for (char c : s.toCharArray()) {
            builder.append(c);
            builder.append('#');
        }
        builder.append('!');
        String t = builder.toString();

        int center = 1, rmax = 1, total = 0;
        int[] dp = new int[t.length()];
        Arrays.fill(dp, 1);
        for (int i = 2; i < t.length() - 1; i++) {
            if (i <= rmax) {
                int idx = 2 * center - i;
                dp[i] = Math.min(dp[idx], rmax - i + 1);
            }
            while (t.charAt(i - dp[i]) == t.charAt(i + dp[i])) dp[i]++;
            if (dp[i] > rmax) {
                rmax = dp[i] + i - 1;
                center = i;
            }
            total += dp[i] / 2;
        }
        return total;
    }
}
