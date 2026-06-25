class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[l] != 0) { //check if nonzero, if true skip
                ++l;
            }
            else {
                while (nums[r] == 0) { //find first nonzero
                    ++r;
                    if (r >= nums.size()) return;
                }
                //nonzero has been found and we haven't gone to the end of the list
                nums[l] = nums[r];
                nums[r] = 0;
                ++l;
            }
        }
    }
};