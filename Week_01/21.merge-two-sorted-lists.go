/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (64.26%)
 * Total Accepted:    365.7K
 * Total Submissions: 568.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := ListNode{Val: 0, Next: nil}
    current, head := &dummy, &dummy
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            current.Next = l1
            if head == nil {
                head = l1
            }
            l1 = l1.Next
        } else {
            current.Next = l2
            if head == nil {
                head = l2
            }
            l2 = l2.Next
        }
        current = current.Next
    }
    if l1 != nil {
        current.Next = l1
    }
    if l2 != nil {
        current.Next = l2
    }
    return head.Next
}
