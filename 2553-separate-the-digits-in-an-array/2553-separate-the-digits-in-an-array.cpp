class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int ni = nums.size();
        for(int i = ni-1; i>=0; i--){
            int n = nums[i];
            
         while(n>0){
            int k = n % 10;
            ans.push_back(k);
            n = n/10;
         }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};