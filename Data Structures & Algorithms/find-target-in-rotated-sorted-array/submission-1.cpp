class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto l = nums.begin();
        auto r = nums.end();
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (*mid == target) return mid - nums.begin();
            if (*l < *mid) { //left half is sorted
                if (*l <= target && target < *mid) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            } else {
                if (*mid < target && target <= *(r-1)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        return -1;
    }
};
