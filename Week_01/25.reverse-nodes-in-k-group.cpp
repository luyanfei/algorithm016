/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (62.89%)
 * Total Accepted:    100K
 * Total Submissions: 159K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* latter = head; //latter有下一节点的含义
        int count = 0;
        for (; count < k && latter != NULL; count++, latter = latter->next) ;
        if (count < k) {
            return head;
        }
        latter = reverseKGroup(latter, k);
        while (count--) {
            ListNode* tmp = head->next;
            head->next = latter;
            latter = head;
            head = tmp;
        }
        return latter;
    }
};
