class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;

        int s = 0;
        int s2 = n;

        while(s2 < 2*n){
            ans.push_back(nums[s++]);
            ans.push_back(nums[s2++]);
        }
        return ans;
    }
};