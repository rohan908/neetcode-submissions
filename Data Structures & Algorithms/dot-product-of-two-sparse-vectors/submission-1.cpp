class SparseVector {
public:

    //hash map of the key and the value
    std::vector<std::pair<int, int>> sv;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                sv.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int totalSum = 0;
        int j = 0;
        int i = 0;
        int index1;
        int index2;
        while (i < sv.size() && j < vec.sv.size()) {
            index1 = sv[i].first;
            index2 = vec.sv[j].first;

            if (index1 < index2) {
                ++i;
            }
            else if (index1 > index2) {
                ++j;
            }
            else {
                totalSum += sv[i].second * vec.sv[j].second;
                ++i;
                ++j;
            }
        }
        return totalSum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
