class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        // Step 1: Flatten
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }
        
        // Step 2: Check feasibility
        int rem = arr[0] % x;
        for (int val : arr) {
            if (val % x != rem) return -1;
        }
        
        // Step 3: Sort
        sort(arr.begin(), arr.end());
        
        // Step 4: Median
        int n = arr.size();
        int median = arr[n / 2];
        
        // Step 5: Count operations
        int ops = 0;
        for (int val : arr) {
            ops += abs(val - median) / x;
        }
        
        return ops;
    }
};