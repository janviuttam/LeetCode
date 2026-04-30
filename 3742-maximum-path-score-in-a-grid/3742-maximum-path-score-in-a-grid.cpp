class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        // Start
        int startCost = (grid[0][0] == 0 ? 0 : 1);
        if (startCost <= k)
            dp[0][0][startCost] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    // Move right
                    if (j + 1 < m) {
                        int newCost = c + (grid[i][j+1] == 0 ? 0 : 1);
                        if (newCost <= k) {
                            dp[i][j+1][newCost] = max(
                                dp[i][j+1][newCost],
                                dp[i][j][c] + grid[i][j+1]
                            );
                        }
                    }

                    // Move down
                    if (i + 1 < n) {
                        int newCost = c + (grid[i+1][j] == 0 ? 0 : 1);
                        if (newCost <= k) {
                            dp[i+1][j][newCost] = max(
                                dp[i+1][j][newCost],
                                dp[i][j][c] + grid[i+1][j]
                            );
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n-1][m-1][c]);
        }

        return ans;
    }
};