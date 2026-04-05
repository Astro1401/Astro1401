class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1) , hash(n);

        int maxi = 1;
        int lastindex = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastindex]);

        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};