class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        unsigned m = matrix.size();
        if (matrix[0].empty()) return false;
        unsigned n = matrix[0].size();

        unsigned int low = 0;
        unsigned int high = m * n - 1;

        while (low <= high) {
            unsigned int mid = (low + high) >> 1;
            unsigned int row = mid / n;
            unsigned int col = mid % n;
            cout << to_string(low) + " " + to_string(mid) + " " + to_string(high) + "\n" << endl;

            if (matrix[row][col] < target) {
                low = mid + 1;
            }
            else if (matrix[row][col] > target){
                if (mid == 0) break;
                else {
                    high = mid - 1;
                }
            }
            else {
                return true;
            }
        }
        return false;

        
    }
};
