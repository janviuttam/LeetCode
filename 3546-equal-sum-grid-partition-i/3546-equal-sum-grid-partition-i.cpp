class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        long long totalSum = 0;
        
        // Calculate total sum
        for (auto &row : grid) {
            for (auto &val : row) {
                totalSum += val;
            }
        }
        
        // If total sum is odd → cannot split equally
        if (totalSum % 2 != 0) return false;
        
        long long target = totalSum / 2;
        
        // Check horizontal cuts
        long long currSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                currSum += grid[i][j];
            }
            if (currSum == target) return true;
        }
        
        // Check vertical cuts
        currSum = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                currSum += grid[i][j];
            }
            if (currSum == target) return true;
        }
        
        return false;
    }
};