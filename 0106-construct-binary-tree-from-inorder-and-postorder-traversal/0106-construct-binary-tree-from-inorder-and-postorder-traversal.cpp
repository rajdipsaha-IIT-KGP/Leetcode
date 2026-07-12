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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,map<int,int>&mp,int is,int ie,int ps,int pe){
        if(ps > pe || is > ie)
        return nullptr;
        
        int ir = mp[postorder[pe]];
        int nl = ir - is;
        TreeNode* root = new TreeNode(postorder[pe]);
        root->left = build(inorder,postorder,mp,is,ir-1,ps,ps+nl-1);
        root->right = build(inorder,postorder,mp,ir+1,ie,ps + nl,pe-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        map<int,int>mp;

        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* node = build(inorder,postorder,mp,0,n-1,0,n-1);

        return node;

    }
};