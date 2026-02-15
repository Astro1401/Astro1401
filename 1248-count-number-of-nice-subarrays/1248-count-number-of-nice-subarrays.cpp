class Solution {
private: int aloo(vector<int> &nums, int k){

     if(k<0) return 0;
        int l=0 , r=0 , cnt =0, sum =0;

        while(r<nums.size()){
            sum +=nums[r]%2;
            while(sum>k){
                sum = sum - nums[l]%2;
                l++;
            }
            cnt = cnt + (r-l+1);
            r=r+1;
        }
        return cnt;
}

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return aloo(nums,k)- aloo(nums,k-1);
    }
};