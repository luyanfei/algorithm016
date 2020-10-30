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

