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
int ans = 1e9;
    TreeNode* prev = nullptr;
    void f(TreeNode* root){
        if(!root)
        return ;
       f(root->left);
       if(prev)
       ans = min(ans,abs(prev->val - root->val));
       prev = root;
        
        f(root->right);
        
        return;
    }
    int minDiffInBST(TreeNode* root) {
        f(root);
        return ans;
    }
};