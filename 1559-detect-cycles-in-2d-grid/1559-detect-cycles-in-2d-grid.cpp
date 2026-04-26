class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        vis[x][y] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == grid[x][y]) {

                if (!vis[nx][ny]) {
                    if (dfs(grid, nx, ny, x, y))
                        return true;
                }
                else if (!(nx == px && ny == py)) {
                    // visited and not parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }
        return false;
    }
};