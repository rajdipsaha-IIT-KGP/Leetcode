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
    bool f(TreeNode* root,int sum,int targetSum){
        if(!root)
        return false;
         if(!root->left && !root->right){
            return sum+root->val == targetSum;
         }
         return f(root->left,sum + root->val,targetSum) || f(root->right,sum + root->val,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root,0,targetSum);
    }
};