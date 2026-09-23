class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int sum = 0;

        mp[0] = -1;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            mp[sum] = i;
        }

        int remain = sum - x;
        if(remain < 0) return -1;
        int longest = INT_MIN;

        sum = 0;

        for(int i = 0; i<n; i++){
            sum += nums[i];

            int findsum = sum - remain;
            
            if(mp.find(findsum) != mp.end()){
                
                int idx = mp[findsum];

                longest = max(longest, i - idx);
            }
        }
        return longest == INT_MIN ? -1 : n - longest;
    }
};