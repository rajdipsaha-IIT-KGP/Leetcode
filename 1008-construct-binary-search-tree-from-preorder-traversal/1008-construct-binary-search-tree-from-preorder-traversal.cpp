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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
         return build(preorder,INT_MAX,i);
    }
    TreeNode* build(vector<int>& preorder,int ub,int& i){
        if(i == preorder.size() || preorder[i] > ub)
        return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder,root->val,i);
        root->right = build(preorder,ub,i);

        return root;
    }
};