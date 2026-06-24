class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> rc;
        for (int i = 0; i < nums.size(); ++i) {
            int pairNum = target - nums[i];
            if (hashmap.contains(pairNum)) {
                rc = {hashmap[pairNum], i};
                return rc;
            }
            hashmap[nums[i]] = i;
        }
        std::cout << "did not find" << std::endl;
        return rc;
    }
};
