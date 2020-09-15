/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (73.88%)
 * Total Accepted:    44.5K
 * Total Submissions: 60.2K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的前序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其前序遍历: [1,3,5,6,2,4]。
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* top = s.top();
            s.pop();
            result.push_back(top->val);
            for (int i = top->children.size() - 1; i >= 0; i--) {
                s.push(top->children[i]);
            }
        }
        return result;
    }
};
