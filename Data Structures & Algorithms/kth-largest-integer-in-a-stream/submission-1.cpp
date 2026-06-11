class KthLargest {
private:
priority_queue<int, vector<int>, greater<int>> minHeap;
int k;

public:
    KthLargest(int k, vector<int>& nums) : k(k){
        for (int num : nums) {
            minHeap.emplace(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.emplace(val);
        if (minHeap.size() > this->k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
