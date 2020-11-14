/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (73.45%)
 * Total Accepted:    101.6K
 * Total Submissions: 138.3K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入："Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 * 
 */
class Solution {
public:
    string reverseWords(string s) {
        auto reverseWord = [&] (int start, int end) {
            int left = start, right = end - 1;
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        };
        int pre = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverseWord(pre, i);
                pre = i + 1;
            }
        }
        if (pre < s.size()) {
            reverseWord(pre, s.size());
        }
        return s;
    }
};
