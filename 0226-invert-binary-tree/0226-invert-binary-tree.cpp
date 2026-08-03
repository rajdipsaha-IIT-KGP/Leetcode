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
    TreeNode* f(TreeNode* root){
        if(!root)
        return NULL;

        TreeNode* node = new TreeNode(root->val);
        node->left = f(root->right);
        node->right = f(root->left);

        return node;

    }
    TreeNode* invertTree(TreeNode* root) {
         return f(root);
    }
};