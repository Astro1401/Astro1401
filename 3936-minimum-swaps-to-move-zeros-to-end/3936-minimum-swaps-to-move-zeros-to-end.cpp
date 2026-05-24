class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zercnt = 0 , lastzeros = 0;
        int n = nums.size();
       
        for(int i = 0; i<n; i++){
             if(nums[i] == 0) zercnt++;
        }
        int q = zercnt;
        for(int i = n-1; q>0; i--){
             if(nums[i] == 0) lastzeros++;
             q--;
        }

        return zercnt-lastzeros;
    }
};