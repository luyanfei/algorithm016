/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (61.99%)
 * Total Accepted:    18.4K
 * Total Submissions: 29.7K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 您需要在二叉树的每一行中找到最大的值。
 * 
 * 示例：
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * 输出: [1, 3, 9]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static bool compare(TreeNode* a, TreeNode* b) {
    return a->val < b->val;
}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        vector<TreeNode*> q{root};
        while (!q.empty()) {
            vector<TreeNode*> newq;
            for (auto node : q) {
                if (node->left != nullptr) {
                    newq.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    newq.emplace_back(node->right);
                }
            }
            TreeNode* maxnode = *max_element(q.begin(), q.end(), compare);
            result.push_back(maxnode->val);
            q = newq;
        }
        return result;
    }
};
