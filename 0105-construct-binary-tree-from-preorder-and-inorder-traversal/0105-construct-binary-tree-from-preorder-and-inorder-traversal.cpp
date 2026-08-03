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
    TreeNode* build(map<int,int>& mp,vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie){
        if(pe < ps || ie < is)
        return nullptr;
        int ir = mp[preorder[ps]];
        int nl = ir - is;
        TreeNode* node = new TreeNode(preorder[ps]);

        node->left = build(mp,preorder,inorder,ps+1,ps+nl,is,ir-1);
        node->right = build(mp,preorder,inorder,ps+nl+1,pe,ir+1,ie);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n = preorder.size();

        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }
        return build(mp,preorder,inorder,0,n-1,0,n-1);

    }
};