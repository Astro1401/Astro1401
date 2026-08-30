class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 1e9; int maxi = INT_MIN;
        int minidx = 0; int maxidx = 0;
        int n  = nums.size();
        
        if(n == 1) return 1;

        for(int i = 0; i<n; i++){
             if(nums[i] < mini) {
                mini = nums[i]; minidx = i;
             }
             if(nums[i] > maxi) {
                maxi = nums[i]; maxidx = i;
             } 
        }

        int L = min(minidx, maxidx);
        int R = max(minidx, maxidx);

        int option1 = R + 1;

        int option2 = n - L;

        int option3 = (L + 1) + (n - R);

        return min({option1, option2, option3});
    }
};