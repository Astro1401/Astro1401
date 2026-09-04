class Solution {
public:
    int dfs(int i, int j , vector<vector<int>>& grid, vector<vector<int>> &vis,int &cnt){
        int m = grid.size();
        int n = grid[0].size();
        cnt++;
        vis[i][j] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k = 0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                dfs(nr,nc,grid,vis,cnt);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));

        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    int cnt = 0;
                    dfs(i,j,grid,vis,cnt);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};