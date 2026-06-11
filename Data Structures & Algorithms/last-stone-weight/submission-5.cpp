#include <queue>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> sorted_stones;
        for (int stone : stones) {
            sorted_stones.push(stone);
        }
        while (sorted_stones.size() > 1) {
            int y = sorted_stones.top();
            sorted_stones.pop();
            int x = sorted_stones.top();
            sorted_stones.pop();
            if (y != x) {
                sorted_stones.push(y - x);
            }
        }
        if (sorted_stones.empty()) {
            return 0;
        }
        else {
            return sorted_stones.top();
        }
    }
};