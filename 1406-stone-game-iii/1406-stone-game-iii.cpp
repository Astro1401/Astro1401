class Solution {
public:
    int solve(vector<int> &stoneValue, int i, vector<int> &dp){
        int n = stoneValue.size();
        if(i>=n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int result = stoneValue[i] - solve(stoneValue,i+1,dp);

        if(i+1<n) result = max(result, stoneValue[i] + stoneValue[i+1] - solve(stoneValue, i+2, dp));
 
        if(i+2<n) result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(stoneValue, i+3, dp));

        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,-1);

        int diff = solve(stoneValue,0,dp);
        
        if(diff<0) return "Bob";
        else if(diff>0) return "Alice";

        return "Tie";

    }
};