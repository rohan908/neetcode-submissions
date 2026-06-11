class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = ((unsigned int)low + (unsigned int)high) >> 1;
            bool rc = isPossible(piles, mid, h);
            cout << low;
            cout << mid;
            cout << high;
            cout << rc;
            cout << "\n";
            if (rc) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;

    }

    bool isPossible(vector<int>& piles, int k, int h) {
        int total = 0;
        for (int val : piles) {
            int num_full_hours_eating = val / k;
            total += num_full_hours_eating;

            int r = val - num_full_hours_eating * k;
            if (r > 0) total++;
        }
        cout<<"\ntotal";
        cout << total;
        cout<<"\n";
        if (total > h) {
            return false;
        }
        return true;
    }
};
