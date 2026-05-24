class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (auto it : nums) {
            mp[it]++;

            if (mp[it] <= k) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};