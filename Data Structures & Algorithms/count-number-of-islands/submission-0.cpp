class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int totalIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    totalIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return totalIslands;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j); //down cell
        dfs(grid, i, j + 1); //right cell
        dfs(grid, i - 1, j); //up cell
        dfs(grid, i, j - 1); //left cell
    }
};