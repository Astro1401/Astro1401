class Solution {
public:
    int calc(vector<int> &nums, int k){
        int l = 0; int r = 0;
        map<int,int> mp;
        int cnt = 0;
        
        if(k<0) return 0;
        
        while(r<nums.size()){
          mp[nums[r]]++;

          while (mp.size() > k) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l++;
            }
            
            cnt += r - l + 1;
            r++;

        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calc(nums,k) - calc(nums,k-1);
    }
};