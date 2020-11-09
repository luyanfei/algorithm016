/*
 * @lc app=leetcode.cn id=212 lang=golang
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (42.89%)
 * Total Accepted:    23.4K
 * Total Submissions: 54K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +  '["oath","pea","eat","rain"]'
 *
 * 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
 * 
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 * 
 * 示例:
 * 
 * 输入: 
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * 输出: ["eat","oath"]
 * 
 * 说明:
 * 你可以假设所有输入都由小写字母 a-z 组成。
 * 
 * 提示:
 * 
 * 
 * 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
 * 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
 * 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
 * 
 * 
 */
type TrieNode struct {
    children map[byte]*TrieNode
    ended bool
}
func findWords(board [][]byte, words []string) []string {
    root := &TrieNode{children: make(map[byte]*TrieNode), ended: false}
    insert := func(word string) {
        node := root
        for _, r := range word {
            c := byte(r)
            node.children[c] = &TrieNode{children: make(map[byte]*TrieNode), ended: false}
            node = node.children[c]
        }
        node.ended = true
    }

    for _, word := range words {
        insert(word)
    }

    if len(board) == 0 {
        return make([]string, 0)
    }
    height, width := len(board), len(board[0])
    result, item := make(map[string]bool, 0), make([]byte, 0)
    var dfs func(row, col int, node *TrieNode)
    dfs = func(row, col int, node *TrieNode) {
        if row < 0 || row >= height || col < 0 || col >= width || board[row][col] == '.' {
            return
        }
        c := board[row][col]
        if _, ok := node.children[c]; !ok {
            return
        }
        item = append(item, c)
        node = node.children[c]
        if node.ended {
            result[string(item)] = true
            return
        }
        board[row][col] = '.'
        dfs(row + 1, col, node)
        dfs(row - 1, col, node)
        dfs(row, col + 1, node)
        dfs(row, col - 1, node)
        board[row][col] = c
        item = item[:len(item) - 1]
    }
    
    for i := 0; i < height; i++ {
        for j := 0; j < width; j++ {
            item = make([]byte, 0)
            dfs(i, j, root)
        }
    }

    lst := make([]string, 0)
    for name, _ := range result {
        lst = append(lst, name)
    }
    return lst
}
