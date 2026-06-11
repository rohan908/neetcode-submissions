class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            hashMap.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++) {
            int r = target - nums[i];
            if (hashMap.count(r) && hashMap[r] != i) {
                int j = hashMap[r];
                if (i < j) return {i, j};
                else {return {j,i};}
            }
        }
        return {};
    }
};
