/*
 * @lc app=leetcode.cn id=155 lang=golang
 *
 * [155] Min Stack
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (55.23%)
 * Total Accepted:    159.3K
 * Total Submissions: 288.4K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * pop、top 和 getMin 操作总是在 非空栈 上调用。
 * 
 * 
 */
type MinStack struct {
    Vals []int
    Mins []int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{Vals: []int{}, Mins: []int{math.MaxInt64}}
}


func (this *MinStack) Push(x int)  {
    if len(this.Mins) > 0 {
        top := this.Mins[len(this.Mins) - 1]
        if top > x {
            this.Mins = append(this.Mins, x)
        } else {
            this.Mins = append(this.Mins, top)
        }
    }
    this.Vals = append(this.Vals, x)
}


func (this *MinStack) Pop()  {
    this.Vals = this.Vals[:len(this.Vals) - 1]
    this.Mins = this.Mins[:len(this.Mins) - 1]
}


func (this *MinStack) Top() int {
    return this.Vals[len(this.Vals) - 1]
}


func (this *MinStack) GetMin() int {
    return this.Mins[len(this.Mins) - 1]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
