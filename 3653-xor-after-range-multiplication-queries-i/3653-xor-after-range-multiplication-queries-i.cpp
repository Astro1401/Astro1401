class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int x = 0;
        for(int i = 0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;

            while(idx<=r){
                nums[idx] = (1LL * nums[idx] * v) % MOD;
                idx += k;
            }
                 
        }

        for(auto it : nums){
                 x ^= it; 
            }

        return x;
    }
};