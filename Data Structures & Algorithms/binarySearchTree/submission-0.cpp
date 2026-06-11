class TreeNode {
    public:
        TreeNode* left;
        TreeNode* right;

        int key;
        int val;

        TreeNode(int key, int val) {
            this->key = key;
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};


class TreeMap {
private:
    TreeNode* root;

    void dfs(TreeNode* root, vector<int>& keys) {
        if (root->left) dfs(root->left, keys);
        keys.push_back(root->key);
        if (root->right) dfs(root->right, keys);
    }

    TreeNode* r_remove(TreeNode* curr, int key) {
        if(!curr) return nullptr;
        if (key < curr->key) {
            curr->left = r_remove(curr->left, key);
        }
        else if (key > curr->key){
            curr->right = r_remove(curr->right,key);
        } else {
            // ok we found the node
            // first check if only one child (easy)
            if (!curr->left) return curr->right; //this appends the node to the above recursive call that hit the above if else statment
            if (!curr->right) return curr->left;

            //ok we have two children
            //need to find the min of the right subtree as that will become the next highest node (greater than left tree but less than the rest of the right subtree)
            TreeNode* node = curr->right;
            while (node->left) {
                node = node->left;
            }
            //ok we found the min (sotred in node, now we assign the root (curr) and then we need to delete the original min node)
            curr->key = node->key;
            curr->val = node->val;
            curr->right = r_remove(curr->right, curr->key);

        }
        return curr;
    }

public:
    TreeMap() {
        this->root = nullptr;
    }

    void insert(int key, int val) {
        if (!this->root) this->root = new TreeNode(key, val);
        else {
            TreeNode* curr = this->root;
            bool rc = true;
            while (rc){
                if (key < curr->key) { //go to left branch
                    if (!curr->left) {
                        curr->left = new TreeNode(key, val);
                        rc = false;
                    }
                    else{
                        curr = curr->left;
                    }
                }
                else if (key > curr->key) {
                    if (!curr->right) {
                        curr->right = new TreeNode(key, val);
                        rc = false;
                    }
                    else {
                        curr = curr->right;
                    }
                }
                else { //key is equal to current node => replace
                    curr->val = val;
                    rc = false;
                }
            }
        }
    }



    int get(int key) {
        TreeNode* curr = this->root;
        while (curr) {
            if (key < curr->key) {
                curr = curr->left;
            }
            else if (key > curr->key) {
                curr = curr->right;
            }
            else {
                return curr->val;
            }
        }
        return -1;
    }

    int getMin() {
        if (!this->root) return -1;
        TreeNode* curr = this->root;
        while (curr->left) {
            curr = curr->left;
        }
        return curr->val;
    }

    int getMax() {
        if (!this->root) return -1;
        TreeNode* curr = this->root;
        while (curr->right) {
            curr = curr->right;
        }
        return curr->val;
    }

    void remove(int key) {
       this->root = r_remove(this->root, key);
    }

    std::vector<int> getInorderKeys() {
        //dfs (left, root, right)
        std::vector<int> keys;
        if (!this->root) return keys;
        dfs(this->root, keys);
        return keys;
    }

    
};
