/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (47.32%)
 * Total Accepted:    44.2K
 * Total Submissions: 93.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 * 
 * 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 * 
 * 说明：
 * 
 * 
 * 字母异位词指字母相同，但排列不同的字符串。
 * 不考虑答案输出的顺序。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s: "cbaebabacd" p: "abc"
 * 
 * 输出:
 * [0, 6]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s: "abab" p: "ab"
 * 
 * 输出:
 * [0, 1, 2]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 
 * 
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return vector<int>();
        vector<int> parr(26, 0);
        for (const char c : p) {
            parr[c - 'a']++;
        }

        auto isanagram = [&] (vector<int>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] != parr[i]) {
                    return false;
                }
            }
            return true;
        };
        
        int psize = p.size();
        vector<int> sarr(26, 0);
        for (int i = 0; i < psize; i++) {
            sarr[s[i] - 'a']++;
        }
        vector<int> result;
        if (isanagram(sarr)) {
            result.push_back(0);
        }
        for (int i = psize; i < s.size(); i++) {
            sarr[s[i - psize] - 'a']--;
            sarr[s[i] - 'a']++;
            if (isanagram(sarr)) {
                result.push_back(i - psize + 1);
            }
        }
        return result;
    }
};
