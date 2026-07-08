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
    int mx = INT_MIN;
    int getmxSum(TreeNode* node){
        if(!node)
        return 0;
       int lcs = max(0,getmxSum(node->left));
        int rcs = max(0,getmxSum(node->right));
        mx = max(mx,lcs + rcs + node->val);
        return node->val + max(lcs,rcs);
    }
    int maxPathSum(TreeNode* root) {
        getmxSum(root);
        return mx;
    }
};