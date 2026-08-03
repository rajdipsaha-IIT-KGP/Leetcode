class Solution {
public:
    int sum = 0;

    void f(TreeNode* root, string &s) {
        if (!root) return;

        if (!root->left && !root->right) {
            sum += stoi(s);
            return;
        }

        if (root->left) {
            s.push_back(root->left->val + '0');
            f(root->left, s);
            s.pop_back();
        }

        if (root->right) {
            s.push_back(root->right->val + '0');
            f(root->right, s);
            s.pop_back();
        }
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;

        string s;
        s.push_back(root->val + '0');

        f(root, s);

        return sum;
    }
};