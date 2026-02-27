class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind<0) return 0;
        if(ind == 0) return nums[0];

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + f(ind-2,nums,dp);
        int nottake = 0 + f(ind-1,nums,dp);

        return dp[ind] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp1;
        vector<int> temp2;
        if(n==1) return nums[0];
        for(int i = 0; i<n; i++){
            if(i < n-1) temp1.push_back(nums[i]);
            if(i != 0)  temp2.push_back(nums[i]);
        }
        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);

        return max(f(n-2, temp1, dp1), f(n-2, temp2, dp2));

    }
};