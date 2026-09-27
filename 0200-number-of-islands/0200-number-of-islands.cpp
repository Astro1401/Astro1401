class Solution {
public:
    void dfs(vector<vector<int>> &vis, vector<vector<char>>& grid, int i , int j){
        
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k = 0; k<4; k++){
            
            int nr = dr[k] + i;
            int nc = dc[k] + j;

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == '1'){
                dfs(vis,grid,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    cnt++;
                    dfs(vis,grid,i,j);
                }
            }
        }
        return cnt;
    }
};