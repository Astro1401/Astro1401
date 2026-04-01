class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int total = 0;
       int n = nums.size();
       for(auto it : nums) total += it;

      if(total - target < 0 || (total - target) % 2 == 1) return 0;

     int k = (total - target) / 2;
   

    vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

    // Base case
    if(nums[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(nums[0] != 0 && nums[0] <= k)
        dp[0][nums[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            long long nottake = dp[i-1][j];

            long long take = 0;
            if(nums[i] <= j)
                take = dp[i-1][j - nums[i]];

            dp[i][j] = (take + nottake);
        }
    }

    return dp[n-1][k];
    }
};