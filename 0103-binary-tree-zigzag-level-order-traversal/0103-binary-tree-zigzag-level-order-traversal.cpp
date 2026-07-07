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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root)
        return ans;
        q.push(root);
       int x = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int>level;
            
            for(int i = 0 ; i < n ; i++){
               TreeNode* node = q.front();
               q.pop();
               if(node->left)
               q.push(node->left);
               if(node->right)
               q.push(node->right);
               level.push_back(node->val);
            }
           if(x == 1){
              ans.push_back(level);
              x = 2;
           }
           else{
            reverse(level.begin(),level.end());
            ans.push_back(level);
              x = 1;
           }
           

        }
        return ans;
    }
};