class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        vector<vector<int>> type = {
            {},
            {2,3},    // 1
            {0,1},    // 2
            {2,1},    // 3
            {3,1},    // 4
            {2,0},    // 5
            {3,0}     // 6
        };

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == n-1 && y == m-1) return true;

            for(int d : type[grid[x][y]]) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]) continue;

                int opp = (d==0)?1:(d==1)?0:(d==2)?3:2;

                // check if next cell connects back
                for(int nd : type[grid[nx][ny]]) {
                    if(nd == opp) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }
        return false;
    }
};