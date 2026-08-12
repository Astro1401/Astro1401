class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0, maxlen = 0;

        for (int j = 0; j < n; j++) {
            
            mp[nums[j]]++;

            while (mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
        }

        return maxlen;
    }
};