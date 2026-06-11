class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //two heaviest stones -> use them (get first two elements from a maxheap)

        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            cout << first;
            maxHeap.pop();
            int second = maxHeap.top();
            cout << second;
            maxHeap.pop();
            if (second < first) {
                maxHeap.push(first - second);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};
