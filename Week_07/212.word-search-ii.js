/*
 * @lc app=leetcode.cn id=212 lang=javascript
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (42.89%)
 * Total Accepted:    23.4K
 * Total Submissions: 54K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
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
/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(board, words) {
    let root = {children: {}}
    let insert = function(word) {
        let node = root
        for (let c of word) {
            if (!(c in node.children)) {
                node.children[c] = {children: {}, ended: false}
            }
            node = node.children[c]
        }
        node.ended = true
    }
    for (let word of words) {
        insert(word)
    }
    let m = board.length, n = board[0].length
    let item = ''
    let rset = new Set()
    let dfs = function(row, col, node) {
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return
        }
        if (board[row][col] === '.') return
        let c = board[row][col]
        if (!node.children[c]) return
        let oldc = c
        board[row][col] = '.'
        item += c
        let nnode = node.children[c]
        if (nnode.ended === true) {
            rset.add(item)
        }
        dfs(row + 1, col, nnode)
        dfs(row - 1, col, nnode)
        dfs(row, col + 1, nnode)
        dfs(row, col - 1, nnode)
        board[row][col] = oldc
        item = item.substring(0, item.length - 1)
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            dfs(i, j, root)
        }
    }
    return [...rset.values()]
};
