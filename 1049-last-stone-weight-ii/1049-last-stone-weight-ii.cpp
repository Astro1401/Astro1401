class Solution {
public:

    int dfs(int i, int total, vector<int>& stones, int sum,
            vector<vector<int>>& dp) {

        if (i == stones.size()) {
            return abs(total - (sum - total));
        }


        if (dp[i][total] != -1) return dp[i][total];

        int notTake = dfs(i + 1, total, stones, sum, dp);

        int take = dfs(i + 1, total + stones[i], stones, sum, dp);

        return dp[i][total] = min(take, notTake);

    }


    int lastStoneWeightII(vector<int>& stones) {

        int sum = 0;
        int n = stones.size();

        for (int x : stones) {
            sum += x;
        }

        vector<vector<int>> dp(n,vector<int>(sum + 1, -1));

        return dfs(0, 0, stones, sum, dp);
    }
};