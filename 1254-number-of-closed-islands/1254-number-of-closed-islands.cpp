class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
           
        vis[i][j] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k = 0; k<4; k++){
             int nr = dr[k] + i;
             int nc = dc[k] + j;

             if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc] == 0 && grid[nr][nc] == 0){
                dfs(nr,nc,grid,vis);
             }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int j = 0; j<n; j++){
            if(grid[0][j] == 0 && vis[0][j] == 0){
                    dfs(0,j,grid,vis);
            }
 
            if(grid[m-1][j] == 0 && vis[m-1][j] == 0){
                    dfs(m-1,j,grid,vis);
            }
         }

         for(int i = 0; i<m; i++){
            if(grid[i][0] == 0 && vis[i][0] == 0){
                    dfs(i,0,grid,vis);
            }
 
            if(grid[i][n-1] == 0 && vis[i][n-1] == 0){
                    dfs(i,n-1,grid,vis);
            }
         }
         int cnt = 0;
         for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};