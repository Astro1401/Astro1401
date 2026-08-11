class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        for(auto it : nums){
         mp[it]++;
        }
        int sum = nums[0];
        
        for(int i = 1; i<nums.size();i++){
            if(nums[i-1] + 1 == nums[i]) sum += nums[i];
            else break;
        }

        while(true){
            if(mp.find(sum) != mp.end()) sum++;
            else return sum;
        }
        return 0;
    }
};