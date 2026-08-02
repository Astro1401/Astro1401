class Solution {
public:
    int n;
    int solve(vector<int>& piles, int person, int i, int m, vector<vector<vector<int>>> &dp){
        if(i>=n) return 0;
        
        if(dp[i][m][person] != -1) return dp[i][m][person];
        
        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        for(int x = 1; x <= min(2*m, n-i); x++){
            stones += piles[i+x-1];

            if(person == 1){
                result = max(result ,stones + solve(piles,0,i+x,max(m,x),dp));
            }
            else{
                result = min(result, solve(piles,1,i+x,max(m,x),dp));
            }
        }
        return dp[i][m][person] = result;
    }
    int stoneGameII(vector<int>& piles) {
         n = piles.size();
        
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(n + 1, vector<int>(2, -1)));
        
         return solve(piles,1,0,1,dp);
    }
};