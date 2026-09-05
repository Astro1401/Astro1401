class Solution {
private:
    int solve(int k, vector<int> &nums) {
        int const n = nums.size();
        int maxi = -1e9, mini = 1e9;
        
        vector<int> rightMini(n);
        
        for(int idx = n - 1; idx >= 0; idx--) {
            mini = min(mini, nums[idx]);
            rightMini[idx] = mini;
        }
        for(int idx = 0; idx < n; idx++) {
            maxi = max(maxi, nums[idx]);
            int score = maxi - rightMini[idx];
            if(score <= k) return idx;
        }
        return -1;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        return solve(k, nums);
    }
};