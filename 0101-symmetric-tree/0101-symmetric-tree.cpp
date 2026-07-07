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
    bool isSym(TreeNode* p1,TreeNode* p2){
        if(!p1 && !p2)
        return true;
        if(!p1 || !p2)
        return false;
        return (p1->val == p2->val) && isSym(p1->left,p2->right) && isSym(p1->right,p2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left,root->right);
    }
};