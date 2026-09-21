class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        
        if(dp[i][j] != -1) return dp[i][j];

        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        long long ans = 1;

        for(int k = 0; k < 4; k++) {
            
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > grid[i][j]) {
                  ans = (ans + solve(nr, nc, grid, dp)) % mod;
            }
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                 ans = (ans + solve(i, j, grid, dp)) % mod;
            }
        }
        return ans;
    }
};