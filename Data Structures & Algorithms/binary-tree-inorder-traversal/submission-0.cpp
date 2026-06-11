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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if (!root) return vec;
        r_helper(root, vec);
        return vec;
    }

    void r_helper(TreeNode* root, vector<int>& vec) {
        if (root->left) r_helper(root->left, vec);
        vec.push_back(root->val);
        if (root->right) r_helper(root->right, vec);
    }
};