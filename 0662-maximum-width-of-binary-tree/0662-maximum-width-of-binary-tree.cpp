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
   typedef unsigned long long ull;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        int ans = INT_MIN;
        while(!q.empty()){
            
            ull mnIndex = q.front().second;
            ull sz = q.size();
            ull first,last;

            for(int i = 0 ; i < sz ; i++){
                
               TreeNode* node = q.front().first;
               ull currIndex = q.front().second - mnIndex;
                     q.pop();
                if(i == 0){
                  first = currIndex;
                }
                if(i == sz - 1)
                last = currIndex;

                if(node->left){
                    q.push({node->left,2*currIndex + 1});
                }
                if(node->right){
                    q.push({node->right,2*currIndex + 2});
                }
            }
            ans = max(ans,(int)(last - first + 1));
        }
      return ans;

    }
};