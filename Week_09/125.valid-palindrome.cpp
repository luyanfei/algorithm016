/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (46.58%)
 * Total Accepted:    176.8K
 * Total Submissions: 379.4K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
class Solution {
public:
    inline bool iseq(char a, char b) {
        if (a >= '0' && a <= '9')
            return a == b;
        char ta = a >= 'a' && a <= 'z' ? a - 'a' + 'A' : a;
        char tb = b >= 'a' && b <= 'z' ? b - 'a' + 'A' : b;
        return ta == tb;
    }
    inline bool isalnum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (isalnum(s[i]) && isalnum(s[j])) {
                if (!iseq(s[i], s[j])) 
                    return false;
                i++;
                j--;
            } else {
                if (!isalnum(s[i])) i++;
                if (!isalnum(s[j])) j--;
            }
        }
        return true;
    }
};
