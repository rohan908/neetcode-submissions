class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum{};
        for (int num : nums) {
            sum += num;
        }
        int shouldBeSum = nums.size() * (nums.size() + 1) / 2;
        return shouldBeSum - sum;
    }
};
