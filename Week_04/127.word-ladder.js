/*
 * @lc app=leetcode.cn id=127 lang=javascript
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (43.68%)
 * Total Accepted:    62K
 * Total Submissions: 141.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */
/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
    let wordSet = new Set(wordList)
    const table = 'abcdefghijklmnopqrstuvwxyz'
    let gen = function(word) {
        let result = []
        for (let i = 0; i < word.length; i++) {
            for (let j = 0; j < table.length; j++) {
                let wordlst = [...word]
                wordlst[i] = table[j]
                let tword = wordlst.join('')
                if (wordSet.has(tword)) {
                    result.push(tword)
                    wordSet.delete(tword)
                }
            }
        }
        return result
    }

    let q = [beginWord]
    let level = 1
    while (q.length > 0) {
        let newq = []
        level++
        for (let i = 0; i < q.length; i++) {
            let generated = gen(q[i])
            for (let j = 0; j < generated.length; j++) {
                if (generated[j] === endWord) {
                    return level
                }
                newq.push(generated[j])
            }
        }
        q = newq
    }
    return 0
};
