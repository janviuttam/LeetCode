class Solution {
public:
    multiset<int> st;      // stores elements
    multiset<int> diff;    // stores differences between DISTINCT neighbors

    void add(int x) {
        auto it = st.insert(x);

        auto prev = it, next = it;
        bool hasPrev = false, hasNext = false;

        if (it != st.begin()) {
            prev--;
            hasPrev = true;
        }

        next++;
        if (next != st.end()) hasNext = true;

        // remove old gap
        if (hasPrev && hasNext) {
            int oldGap = *next - *prev;
            if (*next != *prev) {
                auto it2 = diff.find(oldGap);
                if (it2 != diff.end()) diff.erase(it2);
            }
        }

        // add new gaps (only if distinct)
        if (hasPrev && *it != *prev) {
            diff.insert(*it - *prev);
        }

        if (hasNext && *next != *it) {
            diff.insert(*next - *it);
        }
    }

    void remove(int x) {
        auto it = st.find(x);

        auto prev = it, next = it;
        bool hasPrev = false, hasNext = false;

        if (it != st.begin()) {
            prev--;
            hasPrev = true;
        }

        next++;
        if (next != st.end()) hasNext = true;

        // remove current gaps
        if (hasPrev && *it != *prev) {
            auto it2 = diff.find(*it - *prev);
            if (it2 != diff.end()) diff.erase(it2);
        }

        if (hasNext && *next != *it) {
            auto it2 = diff.find(*next - *it);
            if (it2 != diff.end()) diff.erase(it2);
        }

        // restore gap between neighbors
        if (hasPrev && hasNext && *next != *prev) {
            diff.insert(*next - *prev);
        }

        st.erase(it);
    }

    int getMin() {
        if (st.size() <= 1) return 0;
        return diff.empty() ? 0 : *diff.begin();
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {

            st.clear();
            diff.clear();

            // build first window
            for (int x = i; x < i + k; x++) {
                for (int y = 0; y < k; y++) {
                    add(grid[x][y]);
                }
            }

            ans[i][0] = getMin();

            // slide horizontally
            for (int j = 1; j <= n - k; j++) {

                // remove left column
                for (int x = i; x < i + k; x++) {
                    remove(grid[x][j - 1]);
                }

                // add right column
                for (int x = i; x < i + k; x++) {
                    add(grid[x][j + k - 1]);
                }

                ans[i][j] = getMin();
            }
        }

        return ans;
    }
};