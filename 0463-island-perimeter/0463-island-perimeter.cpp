class Solution {
public:
    int n, m;

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 1;

        if (grid[i][j] == -1)
            return 0;

        grid[i][j] = -1;

        int ans = 0;
        ans += solve(grid, i + 1, j);
        ans += solve(grid, i - 1, j);
        ans += solve(grid, i, j + 1);
        ans += solve(grid, i, j - 1);

        return ans;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return solve(grid, i, j);
                }
            }
        }
        return 0;
    }
};