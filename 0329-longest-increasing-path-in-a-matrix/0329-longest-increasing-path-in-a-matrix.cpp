class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(dp[i][j] != -1)
            return dp[i][j];

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int maxi = 1;

        for(int k = 0; k < 4; k++) {
            
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[i][j]) {
                maxi = max(maxi, 1 + solve(nr, nc, matrix, dp));
            }
        }

        return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans;
    }
};