/*
 * @lc app=leetcode.cn id=208 lang=golang
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (69.04%)
 * Total Accepted:    59.5K
 * Total Submissions: 86.2K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */
type TrieNode struct {
    children map[byte]*TrieNode
    ended bool
}
func newTrieNode() *TrieNode {
    node := make(map[byte]*TrieNode)
    return &TrieNode{children: node, ended: false}
}

type Trie struct {
    root *TrieNode
}

/** Initialize your data structure here. */
func Constructor() Trie {
    return Trie{root: newTrieNode()}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    node := this.root
    for i := 0; i < len(word); i++ {
        if _, ok := node.children[word[i]]; !ok {
            node.children[word[i]] = newTrieNode()
        }
        node = node.children[word[i]]
    }
    node.ended = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    node := this.root
    for i := 0; i < len(word); i++ {
        if _, ok := node.children[word[i]]; !ok {
            return false
        }
        node = node.children[word[i]]
    }
    return node.ended
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    node := this.root
    for i := 0; i < len(prefix); i++ {
        if _, ok := node.children[prefix[i]]; !ok {
            return false
        }
        node = node.children[prefix[i]]
    }
    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
