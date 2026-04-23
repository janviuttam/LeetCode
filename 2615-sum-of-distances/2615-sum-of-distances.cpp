class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // Step 2: process each group
        for (auto &it : mp) {
            vector<int> &indices = it.second;
            int m = indices.size();

            // prefix sum
            vector<long long> prefix(m, 0);
            prefix[0] = indices[0];
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + indices[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                // left side
                if (i > 0) {
                    left = (long long)indices[i] * i - prefix[i - 1];
                }

                // right side
                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - 
                            (long long)indices[i] * (m - i - 1);
                }

                ans[indices[i]] = left + right;
            }
        }

        return ans;
    }
};