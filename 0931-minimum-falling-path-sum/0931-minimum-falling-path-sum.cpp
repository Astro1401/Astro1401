class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int j=0; j<n; j++) dp[0][j] = matrix[0][j];
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<n; j++){
                 int left = 1e9; int right = 1e9;
                 int up = matrix[i][j] + dp[i-1][j];
                 if(j>0)   left = matrix[i][j] + dp[i-1][j-1];
                 if(j<n-1) right = matrix[i][j] + dp[i-1][j+1];

                 dp[i][j] = min(up,min(left,right));
            }
        }

        int maxi = 1e9;

        for(int j = 0; j<n; j++) maxi = min(maxi,dp[n-1][j]);

        return maxi;
    }
};