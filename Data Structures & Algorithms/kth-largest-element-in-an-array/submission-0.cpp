class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for (int num : nums) {
            maxHeap.push(num);
        }

        for (int i = 0; i < k; i++) {
            if (i == k - 1) {
                return maxHeap.top();
            }
            maxHeap.pop();
        }
    }
};
