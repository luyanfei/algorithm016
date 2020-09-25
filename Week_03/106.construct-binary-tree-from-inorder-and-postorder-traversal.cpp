/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (69.73%)
 * Total Accepted:    60.3K
 * Total Submissions: 85.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
    unordered_map<int, int> um;
    int pidx;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int ileft, int iright) {
        if (ileft > iright) {
            return nullptr;
        }
        int val = postorder[pidx];
        int idx = um[val];
        pidx--;
        TreeNode* root = new TreeNode(val);
        root->right = build(inorder, postorder, idx + 1, iright);
        root->left = build(inorder, postorder, ileft, idx - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int isize = inorder.size();
        for (int i = 0; i < isize; ++i) {
            um[inorder[i]] = i;
        }
        pidx = postorder.size() - 1;
        return build(inorder, postorder, 0, isize - 1);
    }
};
