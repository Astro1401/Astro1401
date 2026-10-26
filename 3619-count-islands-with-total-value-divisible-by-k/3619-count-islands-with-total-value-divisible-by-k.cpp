class Solution {
public:
    void dfs(long long i, long long j, vector<vector<int>>& grid, vector<vector<int>>& vis,long long k,long long &sum){
        long long m = grid.size();
        long long n = grid[0].size();
        
        sum += grid[i][j];
        
        vis[i][j] = 1;

        long long dr[] = {-1,0,1,0};
        long long dc[] = {0,1,0,-1};

        for(long long k = 0; k<4; k++){
             long long nr = dr[k] + i;
             long long nc = dc[k] + j;

             if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc] == 0 && grid[nr][nc] != 0){
                dfs(nr,nc,grid,vis,k,sum);
             }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        long long m = grid.size();
        long long n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        long long cnt = 0;

        for(long long i = 0; i<m; i++){
            for(long long j = 0; j<n; j++){
                if(grid[i][j] != 0 && vis[i][j] == 0){
                    long long sum = 0;
                    dfs(i,j,grid,vis,k,sum);
                    if(sum % k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};