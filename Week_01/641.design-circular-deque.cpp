/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] Design Circular Deque
 *
 * https://leetcode-cn.com/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (53.21%)
 * Total Accepted:    11.3K
 * Total Submissions: 21.3K
 * Testcase Example:  '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计实现双端队列。
 * 你的实现需要支持以下操作：
 * 
 * 
 * MyCircularDeque(k)：构造函数,双端队列的大小为k。
 * insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
 * insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
 * deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
 * deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
 * getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
 * getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
 * isEmpty()：检查双端队列是否为空。
 * isFull()：检查双端队列是否满了。
 * 
 * 
 * 示例：
 * 
 * MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
 * circularDeque.insertLast(1);                    // 返回 true
 * circularDeque.insertLast(2);                    // 返回 true
 * circularDeque.insertFront(3);                    // 返回 true
 * circularDeque.insertFront(4);                    // 已经满了，返回 false
 * circularDeque.getRear();                  // 返回 2
 * circularDeque.isFull();                        // 返回 true
 * circularDeque.deleteLast();                    // 返回 true
 * circularDeque.insertFront(4);                    // 返回 true
 * circularDeque.getFront();                // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有值的范围为 [1, 1000]
 * 操作次数的范围为 [1, 1000]
 * 请不要使用内置的双端队列库。
 * 
 * 
 */
class MyCircularDeque {
    vector<int> v;
    int capacity;
    int front;
    int rear;
    int count;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : v(k, 0), capacity(k), front(k - 1), rear(0), count(0) {

    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (count == capacity) {
            return false;
        }
        v[front] = value;
        front = (front - 1 + capacity) % capacity;
        count++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (count == capacity) {
            return false;
        }
        v[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (count == 0) {
            return false;
        }
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (count == 0) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (count == 0) {
            return -1;
        }
        return v[(front + 1) % capacity];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (count == 0) {
            return -1;
        }
        return v[(rear - 1 + capacity) % capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
