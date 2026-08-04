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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        TreeNode* cpy = root;
        while(cpy){
            st.push(cpy);
            cpy = cpy->left;
        }
    }
    
    int next() {
        TreeNode* node = st.top();
        int x = node->val;
        st.pop();
        if(node->right){
            TreeNode* cpy = node->right;
            while(cpy){
                st.push(cpy);
                cpy = cpy->left;

            }
        }
        return x;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */