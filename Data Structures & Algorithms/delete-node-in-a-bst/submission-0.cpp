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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else { //found val
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            //find min in right subtree
            TreeNode* curr = root->right;
            while (curr->left){
                curr = curr->left; //keep finding min in right subtree
            }
            root->val = curr->val;
            //now delete the duplicate key
            root->right = deleteNode(root->right, root->val);    
        }
        return root;
    }
};