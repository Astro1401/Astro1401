class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            if(nums[i] < 0) nums[i] = nums[i]*-1;
        }

        sort(nums.begin(),nums.end());
        long long sum = 0;
        
        for(int i = 0; i< n/2; i++){
           long long ans = nums[i] * nums[i];
           sum -= ans;
        }

        for(int i = n/2; i<n; i++){
            long long anss = nums[i] * nums[i];
            sum += anss;
        }
         
        return sum;

    }
};