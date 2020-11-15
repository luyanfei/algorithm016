/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 救生艇
 *
 * https://leetcode-cn.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (56.17%)
 * Total Accepted:    20.1K
 * Total Submissions: 35.7K
 * Testcase Example:  '"ab-cd"'
 *
 * 给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："ab-cd"
 * 输出："dc-ba"
 * 
 * 
 * 示例 2：
 * 
 * 输入："a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 * 
 * 
 * 示例 3：
 * 
 * 输入："Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S 中不包含 \ or "
 * 
 * 
 */
class Solution {
public:
    inline bool isAlpha(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            if (isAlpha(S[i]) && isAlpha(S[j])) {
                swap(S[i], S[j]);
                i++;
                j--;
            } else {
                if (!isAlpha(S[i])) {
                    i++;
                }
                if (!isAlpha(S[j])) {
                    j--;
                }
            }
        }
        return S;
    }
};
