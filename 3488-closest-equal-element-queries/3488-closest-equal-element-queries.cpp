class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // Store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            auto &vec = mp[nums[q]];
            int sz = vec.size();

            if (sz == 1) {
                ans.push_back(-1);
                continue;
            }

            // Find position of q
            int k = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            // Circular neighbors
            int prev = vec[(k - 1 + sz) % sz];
            int next = vec[(k + 1) % sz];

            int d1 = abs(q - prev);
            int d2 = abs(q - next);

            int res = min({d1, n - d1, d2, n - d2});

            ans.push_back(res);
        }

        return ans;
    }
};