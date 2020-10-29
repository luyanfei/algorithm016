/*
 * @lc app=leetcode.cn id=91 lang=java
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.63%)
 * Total Accepted:    71.1K
 * Total Submissions: 288.7K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 题目数据保证答案肯定是一个 32 位的整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："12"
 * 输出：2
 * 解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2：
 * 
 * 输入："226"
 * 输出：3
 * 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "0"
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "1"
 * 输出：1
 * 
 * 
 * 示例 5：
 * 
 * 输入：s = "2"
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * s 只包含数字，并且可以包含前导零。
 * 
 * 
 */
class Solution {
    public int numDecodings(String s) {
        int[] dp = new int[s.length() + 1];
        Arrays.fill(dp, 0);
        dp[0] = 1;
        dp[1] = s.charAt(0) == '0' ? 0 : 1;
        for (int i = 2; i <= s.length(); i++) {
            if (s.charAt(i - 1) > '0' && s.charAt(i - 1) <= '9') {
                dp[i] = dp[i - 1];
            }
            int val = Integer.valueOf(s.substring(i - 2, i));
            if (val >= 10 && val <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
}
