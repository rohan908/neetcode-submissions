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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        return canReachLeaf(root, targetSum, currSum);
    }

    bool canReachLeaf(TreeNode* root, int targetSum, int& currSum) {
        if (!root) return false;
        currSum += root->val;
        if (currSum == targetSum && !root->left && !root->right) return true;
        if (canReachLeaf(root->left, targetSum, currSum) || canReachLeaf(root->right, targetSum, currSum)) {
            return true;
        }
        currSum -= root->val;
        return false;
    }
};