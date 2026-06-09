class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        if(nums.size() == 1) return 0;
        
        for(auto it : nums){
            if(it>maxi) maxi = it;
            if(it<mini) mini = it;
        }

        return 1LL*k*(maxi-mini);
    }
};