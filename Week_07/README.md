## 单词搜索2用Trie树实现的时间复杂度
$$O(M \cdot 4 \cdot 3^{L - 1})$$

M表示单元格个数，L表示单词的长度。开始搜索时会有四个方向，随后的搜索可以排除出发的方向。

## 双向BFS模板
```
void bibfs(Node* start, Node* end) {
    set<Node*> front {start};
    set<Node*> back {end};
    set<int> visited;
    while (!front.empty()) {
        set<Node*> newset;
        for (const auto& node : front) {
            for (const auto& val : generate_new_nodes(node->val)) {
                if (visited.find(val) != visited.end()) {
                    newset.insert(val);
                }
            }
        }
        front = newset;
        if (front.size() > back.size()) {
            swap(front, back);
        }
    }
    return 0;
}
```

## BFS的实现可以有更多变化
本周的题目给我最大的收获是在实现BFS时的各种变化。

首先是双向BFS，其实实现其实不过是在原来的BFS上多了方向的判断，通过选择较少扩展节点的一方作为下一轮迭代的方向，可以减少扩展节点的数量，从而提升性能。

另一种变化，则是在做leetcode《126. 单词接龙 II》时发现。该题的题解，大多数要结合BFS与DFS，代码量相当大。在查阅国际站的讨论后，发现这个题其实只用BFS是可以解决的，只不过需要用更复杂的数据结构来扩展节点。根据Python的实现，我用C++完成了一次，原来使用队列的地方，变成了Map结构。用Map实现的BFS，也真是大开眼界。
```
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
```
这样的代码，对数据结构的掌控要很清晰才行，层的实现是一个unordered_map，而这个map的值类型是一个二维数组，用于保存与key对应的所有路径。这样的复杂结构，操作起来实在不便，很容易出错，提交后的性能也不是很好，等有空闲，还需要继续琢磨。
