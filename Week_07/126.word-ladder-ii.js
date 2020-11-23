/*
 * @lc app=leetcode.cn id=126 lang=javascript
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
/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {string[][]}
 */
var findLadders = function(beginWord, endWord, wordList) {
    let wordSet = new Set(wordList)
    if (!wordSet.has(endWord)) {
        return new Array()
    }
    let qmap = new Map()
    qmap.set(beginWord, [[beginWord]])
    while (qmap.size !== 0) {
        let nmap = new Map()
        for (let key of qmap.keys()) {
            let value = qmap.get(key)
            if (key === endWord) {
                return value
            }
            for (let i = 0; i < key.length; i++) {
                for (let j = 0; j < 26; j++) {
                    let c = String.fromCharCode('a'.charCodeAt(0) + j)
                    if (c === key[i]) continue
                    let word = key.substring(0, i) + c + key.substring(i + 1)
                    if (!wordSet.has(word)) continue
                    let newvalues = value.map(arr => [...arr, word])
                    if (!nmap.has(word)) {
                        nmap.set(word, [...newvalues])
                    } else {
                        nmap.get(word).push(...newvalues)
                    }
                }
            }
        }
        for (let w of nmap.keys()) {
            wordSet.delete(w)
        }
        qmap = nmap
    }
    return new Array()
};
