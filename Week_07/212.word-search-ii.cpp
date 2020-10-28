/*
 * @lc app=leetcode.cn id=212 lang=cpp
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
class Solution {
    struct TrieNode {
        map<char, TrieNode*> children;
        bool ended;
        TrieNode() : ended(false) {}
        ~TrieNode() {
            for (map<char, TrieNode*>::value_type& elem : children) {
                delete elem.second;
            }
        }
    };
    TrieNode* root;
    void insert(string& s) {
        TrieNode* node = root;
        for (char c : s) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->ended = true;
    };
public:
    Solution() {
        root = new TrieNode();
    };
    ~Solution() {
        delete root;
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& word : words) {
            insert(word);
        }
        set<string> result;
        if (board.size() == 0) return vector<string>();
        int height = board.size(), width = board[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        string item = "";
        function<void(int, int, TrieNode*)> dfs = [&] (int row, int col, TrieNode* node) {
            if (row < 0 || row >= height || col < 0 || col >= width || visited[row][col]) {
                return;
            }
            char c = board[row][col];
            if (node->children.find(c) == node->children.end()) {
                return;
            }
            node = node->children[c];
            item.push_back(c);
            if (node->ended) result.insert(item);
            visited[row][col] = true;
            dfs(row + 1, col, node);
            dfs(row - 1, col, node);
            dfs(row, col + 1, node);
            dfs(row, col - 1, node);
            visited[row][col] = false;
            item.pop_back();
        };
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                dfs(i, j, root);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};
