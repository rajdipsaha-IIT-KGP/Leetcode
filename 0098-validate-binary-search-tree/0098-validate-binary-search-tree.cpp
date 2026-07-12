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
   typedef long long ll;
    bool f(TreeNode* root,ll mx,ll mn){
        if(!root)
        return true;
        if(root->val <= mn || root->val >= mx){
            return false;
        }
       return f(root->left,root->val,mn) && f(root->right,mx,root->val);

    }
    bool isValidBST(TreeNode* root) {
         return f(root,LLONG_MAX,LLONG_MIN);
    }
};