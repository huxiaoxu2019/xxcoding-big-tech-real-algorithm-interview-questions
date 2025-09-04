// https://leetcode.cn/problems/symmetric-tree/
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
class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        queue<TreeNode*> q;
        q.push(left); q.push(right);
        while (q.size()) {
            auto u=q.front(); q.pop();
            auto v=q.front(); q.pop();
            if (!u && !v) continue;
            if (!u || !v) return false;
            if (u->val != v->val) return false;
            q.push(u->left);
            q.push(v->right);
            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};
