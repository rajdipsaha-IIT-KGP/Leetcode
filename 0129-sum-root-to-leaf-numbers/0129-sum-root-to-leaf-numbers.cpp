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
    string s = "";int sum = 0;
    void f(TreeNode* node){
        if(node == nullptr)
        return;
         
         s += char(node->val + '0'); 

        if(!node->left && !node->right){
           sum += stoi(s);
        } else {
           f(node->left);
           f(node->right);
        }
        s.pop_back();
      
    }

    int sumNumbers(TreeNode* root) {
        f(root);
        return sum;
    }
};