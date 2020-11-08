#
# @lc app=leetcode.cn id=146 lang=python3
#
# [146] LRU缓存机制
#
# https://leetcode-cn.com/problems/lru-cache/description/
#
# algorithms
# Medium (50.98%)
# Total Accepted:    109.4K
# Total Submissions: 214.3K
# Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
#
# 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
# 
# 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
# 写入数据 put(key, value) -
# 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
# 
# 
# 
# 进阶:
# 
# 你是否可以在 O(1) 时间复杂度内完成这两种操作？
# 
# 
# 
# 示例:
# 
# LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
# 
# cache.put(1, 1);
# cache.put(2, 2);
# cache.get(1);       // 返回  1
# cache.put(3, 3);    // 该操作会使得关键字 2 作废
# cache.get(2);       // 返回 -1 (未找到)
# cache.put(4, 4);    // 该操作会使得关键字 1 作废
# cache.get(1);       // 返回 -1 (未找到)
# cache.get(3);       // 返回  3
# cache.get(4);       // 返回  4
# 
# 
#
class Node:
    def __init__(self, key = "", value = 0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.size = 0
        self.capacity = capacity
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.map = {}

    def remove(self, node):
        node.prev.next, node.next.prev = node.next, node.prev

    def move_to_head(self, node):
        node.next, self.head.next.prev = self.head.next, node
        node.prev, self.head.next = self.head, node

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        node = self.map[key]
        self.remove(node)
        self.move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.remove(self.map[key])
            self.move_to_head(self.map[key])
            self.map[key].value = value
            return
        self.map[key] = Node(key, value)
        self.move_to_head(self.map[key])
        self.size += 1
        if self.size > self.capacity:
            node = self.tail.prev
            self.remove(node)
            del self.map[node.key]
            self.size -= 1


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
