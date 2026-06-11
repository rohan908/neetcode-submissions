class Solution {
public:
    int search(vector<int>& nums, int target) {
        unsigned int low = 0;
        unsigned int high = nums.size() - 1;

        while (low < high) {
            unsigned int mid = (low + high) >> 1;
            cout << to_string(low) + " " + to_string(high) + " " + to_string(mid) + "\n";
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        if (low < nums.size() && nums[low] == target) return low;
        return -1;
    }
};
