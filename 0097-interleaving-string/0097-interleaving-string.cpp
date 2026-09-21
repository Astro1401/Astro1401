class Solution {
public:
    bool solve(int i , int j ,string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        
        int n = s1.length();
        int m = s2.length();

        if(i == n && j == m && i+j == m+n) return true;

        if(i+j >= m+n) return false;

        if(dp[i][j] != -1) return dp[i][j];
        bool result = false;

        if(s1[i] == s3[i+j]) result = solve(i+1,j,s1,s2,s3,dp);
        if(result) return dp[i][j] = result;

        if(s2[j] == s3[i+j]) result = solve(i,j+1,s1,s2,s3,dp);

        return dp[i][j] = result;

    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.length();
        int m = s2.length();
        int k = s3.length();

        if(n + m != k) return false;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return solve(0,0,s1,s2,s3,dp);
    }
};