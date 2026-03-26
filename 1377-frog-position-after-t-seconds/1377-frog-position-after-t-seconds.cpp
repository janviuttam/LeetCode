class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<tuple<int, double, int>> q;
        vector<bool> visited(n + 1, false);
        
        q.push({1, 1.0, 0});
        visited[1] = true;
        
        while (!q.empty()) {
            auto [node, prob, time] = q.front();
            q.pop();
            
            if (time == t) {
                if (node == target) return prob;
                continue;
            }
            
            int unvisited = 0;
            for (int nei : adj[node]) {
                if (!visited[nei]) unvisited++;
            }
            
            if (unvisited == 0) {
                if (node == target) return prob;
                continue;
            }
            
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, prob / unvisited, time + 1});
                }
            }
        }
        
        return 0.0;
    }
};