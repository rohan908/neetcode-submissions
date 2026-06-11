class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> disMinHeap;
        vector<vector<int>> out;
        for (vector<int> point : points) {
            int dis = (point[0] * point[0] + point[1] * point[1]);
            disMinHeap.push({dis, {point[0], point[1]}});
        }

        for (int i = 0; i < k; i++) {
            pair<int, int> coord = disMinHeap.top().second;
            out.push_back({coord.first, coord.second});
            disMinHeap.pop();
        }
        return out;
    }
};
