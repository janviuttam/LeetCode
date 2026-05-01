class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = 0, f0 = 0;
        
        // Step 1: compute sum and F(0)
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            f0 += (long long)i * nums[i];
        }
        
        long long ans = f0;
        long long prev = f0;
        
        // Step 2: use relation
        for(int k = 1; k < n; k++) {
            long long curr = prev + sum - (long long)n * nums[n - k];
            ans = max(ans, curr);
            prev = curr;
        }
        
        return (int)ans;
    }
};