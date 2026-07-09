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
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,map<int,int>& mp,int preSt,int preEnd,int inSt,int inEnd){
        if(preEnd < preSt || inSt > inEnd){
            return nullptr;
        }
        int inRoot = mp[preorder[preSt]];
        int numsLeft = inRoot - inSt;

        TreeNode* root = new TreeNode(preorder[preSt]);

        root->left = build(preorder,inorder,mp,preSt + 1,preSt + numsLeft,inSt,inRoot-1);
        root->right = build(preorder,inorder,mp,preSt+numsLeft+1,preEnd,inRoot+1,inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }
     
     TreeNode* root = build(preorder,inorder,mp,0,n-1,0,n-1);

     return root;

    }
};