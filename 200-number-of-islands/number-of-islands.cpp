class Solution {
public:
    void bfs(vector<vector<char>>& grid,
             vector<vector<int>>& vis,
             int row, int col) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = x + dr[k];
                int nc = y + dc[k];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == '1' &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size();
        vector<vector<int>> vis( m , vector<int>(n , 0));
        
        int cnt=0;

        for( int row =0 ;row<m ; row++){
            for( int col =0 ;col<n ; col++){
                  if (grid[row][col] == '1' && !vis[row][col]) {
                    cnt++;
                    bfs(grid, vis, row, col);
                  }
            }
        }
        return cnt;
    }

};