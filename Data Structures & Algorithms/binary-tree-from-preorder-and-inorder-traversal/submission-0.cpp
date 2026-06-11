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

//preorder
/*
vist left
output
visit right
*/

//inorder
/*
visit left
*/

class Solution {
int preIdx = 0;
int inIdx = 0;

TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
    //first check if we've ran out of nodes to place
    if(preIdx >= preorder.size()) return nullptr;
    //then check if we've placed everything up to the partition
    if (inorder[inIdx] == limit) {
        inIdx++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[preIdx++]); //get next node to place
    root->left = dfs(preorder, inorder, root->val);
    root->right = dfs(preorder, inorder, limit);
    return root;
}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
