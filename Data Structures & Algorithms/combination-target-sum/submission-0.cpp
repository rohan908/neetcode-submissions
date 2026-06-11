class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> p;
        vector<vector<int>> out;
        dfs(out, nums, p, target, 0);
        return out;
    }

    void dfs(vector<vector<int>>& out, vector<int>& nums, vector<int>& partition, int curr, int i) {
        if (curr == 0) {
            out.push_back(partition);
            return;
        }
        if (curr < 0 || i >= nums.size()) {
            return;
        }

        curr -= nums[i];
        partition.push_back(nums[i]);
        dfs(out, nums, partition, curr, i);
        curr += nums[i];
        partition.pop_back();
        dfs(out, nums, partition, curr, i + 1);
    }
};
