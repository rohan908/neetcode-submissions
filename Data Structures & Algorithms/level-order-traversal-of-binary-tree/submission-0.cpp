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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tq;
        vector<vector<int>> out;
        if (!root) return out;

        tq.push(root);
        while(tq.size() > 0) {
            int layerSize = tq.size();
            vector<int> layer;
            for (int i = 0; i < layerSize; i++) {
                TreeNode* curr = tq.front();
                tq.pop();
                layer.push_back(curr->val);
                if(curr->left) tq.push(curr->left);
                if(curr->right) tq.push(curr->right);
            }
            out.push_back(layer);
        }
        return out;
    }
};
