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


//implement bfs, push the last value in the layer to the output vector
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if (!root) return vec;

        queue<TreeNode*> tq;
        tq.push(root);
        while (tq.size() > 0) {
            int layerSize = tq.size();
            for (int i = 0; i < layerSize; i++) {
                TreeNode* curr = tq.front();
                tq.pop();
                if (curr->left) tq.push(curr->left);
                if (curr->right) tq.push(curr->right);

                if (i == (layerSize - 1)) vec.push_back(curr->val);
            }
        }
        return vec;
        

    }
};
