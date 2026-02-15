class Solution {
private: int aloo(vector<int> &nums, int k){

     if(k<0) return 0;
        int l=0 , r=0 , cnt =0, sum =0;

        while(r<nums.size()){
            sum +=nums[r];
            while(sum>k){
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r=r+1;
        }
        return cnt;
}

public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return aloo(nums,k)- aloo(nums,k-1);
    }
};