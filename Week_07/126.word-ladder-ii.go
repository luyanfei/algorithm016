/*
 * @lc app=leetcode.cn id=126 lang=golang
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
func appendWord(paths [][]string, word string) [][]string {
    result := make([][]string, 0, len(paths))
    for _, path := range paths {
        newpath := append([]string{}, path...)
        newpath = append(newpath, word)
        result = append(result, newpath)
    }
    return result
}
func findLadders(beginWord string, endWord string, wordList []string) [][]string {
    wordSet := make(map[string]bool)
    for _, str := range wordList {
        wordSet[str] = true
    }
    entry := map[string][][]string {
        beginWord: {{beginWord}},
    }
    for len(entry) > 0 {
        newentry := make(map[string][][]string)
        for word, paths := range entry {
            if word == endWord {
                return paths
            }
            wb := []byte(word)
            for i := 0; i < len(wb); i++ {
                for k := 0; k < 26; k++ {
                    c := 'a' + byte(k)
                    if c != wb[i] {
                        temp := append([]byte{}, wb...)
                        temp[i] = c
                        newword := string(temp)
                        if _, ok := wordSet[newword]; ok {
                            newpaths := appendWord(paths, newword)
                            if vpaths, ok := newentry[newword]; ok {
                                newentry[newword] = append(vpaths, newpaths...)
                            } else {
                                newentry[newword] = newpaths
                            }
                        }
                    }
                }
            }
        }
        entry = newentry
        for key, _ := range entry {
            delete(wordSet, key)
        }
    }
    return make([][]string, 0)
}
