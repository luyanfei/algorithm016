/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.99%)
 * Total Accepted:    115.7K
 * Total Submissions: 170.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int, int> inmap;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft, int iright) {
        if (pleft >= pright) {
            return nullptr;
        }
        int rootval = preorder[pleft];
        TreeNode* root = new TreeNode(rootval);
        int index = inmap[rootval];
        root->left = build(preorder, inorder, pleft + 1, pleft + 1 + index - ileft, ileft, index);
        root->right = build(preorder, inorder, pleft + 1 + index - ileft, pright, index + 1, iright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
