class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> subset;
        dfs(nums, out, subset, 0);
        return out;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& out, vector<int>& subset, int depth) {
        if (depth >= nums.size()) {
            out.push_back(subset);
            return;
        }
        cout<<depth;
        cout<<"\n";

        //two branches (include or not include)
        subset.push_back(nums[depth]);
        dfs(nums, out, subset, ++depth);
        depth--;
        subset.pop_back();
        dfs(nums, out, subset, ++depth);
    }
};
