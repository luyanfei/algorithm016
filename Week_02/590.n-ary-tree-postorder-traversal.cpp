/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (74.47%)
 * Total Accepted:    35K
 * Total Submissions: 47K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的后序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其后序遍历: [5,6,3,2,4,1].
 * 
 * 
 * 
 * 说明: 递归法很简单，你可以使用迭代法完成此题吗?
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postTraversal(Node* root, vector<int>& result) {
        if (!root) {
            return;
        }
        for (auto child : root->children) {
            postTraversal(child, result);
        }
        result.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        postTraversal(root, result);
        return result;
    }
};
