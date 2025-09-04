// https://leetcode.cn/problems/symmetric-tree/description/
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
    bool helper(TreeNode* first, TreeNode* second) {
        if (first == nullptr && second == nullptr) return true;
        if (first == nullptr || second == nullptr) return false;
        if (first->val != second->val) return false;
        return helper(first->left, second->right) && helper(first->right, second->left);

    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
}
