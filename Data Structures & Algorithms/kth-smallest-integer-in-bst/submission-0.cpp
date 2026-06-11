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
    int kthSmallest(TreeNode* root, int k) {
        //if (!root) return 0;
        int rc_val = 0;
        r_dfs(root, k, rc_val);
        return rc_val;

    }

    void r_dfs(TreeNode* root, int& k, int& rc_val) {
        if (root->left) r_dfs(root->left, k, rc_val);
        k--;
        if (k == 0) rc_val = root->val;
        if (root->right) r_dfs(root->right, k, rc_val);
    }
};
