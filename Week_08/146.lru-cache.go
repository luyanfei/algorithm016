/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (50.98%)
 * Total Accepted:    109.4K
 * Total Submissions: 214.3K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 */
type Node struct {
    prev, next *Node
    key, value int
}

type LRUCache struct {
    hash map[int]*Node
    head, tail *Node
    size, capacity int
}


func Constructor(capacity int) LRUCache {
    head := &Node{key: 0, value: 0, prev: nil, next: nil}
    tail := &Node{key: 0, value: 0, prev: nil, next: nil}
    head.next, tail.prev = tail, head
    return LRUCache{hash: make(map[int]*Node), head: head, tail: tail, size: 0, capacity: capacity}
}

func (this *LRUCache) Remove(node *Node) {
    node.prev.next, node.next.prev = node.next, node.prev
}
func (this *LRUCache) MoveToHead(node *Node) {
    node.next, node.prev = this.head.next, this.head
    this.head.next.prev, this.head.next = node, node
}
func (this *LRUCache) Get(key int) int {
    if _, ok := this.hash[key]; !ok {
        return -1
    }
    node := this.hash[key]
    this.Remove(node)
    this.MoveToHead(node)
    return node.value
}

func (this *LRUCache) Put(key int, value int)  {
    if node, ok := this.hash[key]; ok {
        node.value = value
        this.Remove(node)
        this.MoveToHead(node)
        return
    }
    newnode := &Node{key: key, value: value, prev: nil, next: nil}
    this.MoveToHead(newnode)
    this.hash[key] = newnode
    this.size++
    if this.size > this.capacity {
        delnode := this.tail.prev
        delete(this.hash, delnode.key)
        this.Remove(delnode)
        this.size--
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
