/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 *
 * https://leetcode-cn.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (38.47%)
 * Total Accepted:    24.9K
 * Total Submissions: 64.6K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord
 * 的最短转换序列。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换后得到的单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回一个空列表。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: []
 * 
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 * 
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<vector<string>>> layer({{beginWord, {{beginWord}}}});
        set<string> wordSet(wordList.begin(), wordList.end());

        while (!layer.empty()) {
            unordered_map<string, vector<vector<string>>> newlayer;
            for (const auto& p : layer) {
                if (p.first == endWord) {
                    return layer[p.first];
                }
                for (int i = 0; i < p.first.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == p.first[i]) continue;
                        string nword = p.first.substr(0, i) + c + p.first.substr(i + 1, p.first.size() - i - 1);
                        if (wordSet.find(nword) == wordSet.end()) continue;
                        vector<vector<string>> npaths = layer[p.first];
                        for (auto v : npaths) {
                            v.push_back(nword);
                            if (newlayer.find(nword) == newlayer.end()) {
                                newlayer[nword] = {v};
                            } else {
                                newlayer[nword].push_back(v);
                            }
                        }
                    }
                }
            }
            for (const auto& p : newlayer) {
                wordSet.erase(p.first);
            }
            layer = newlayer;
        }
        return vector<vector<string>>();
    }
};
