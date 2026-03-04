class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         unordered_map<int,int> mp;

         for(int i = 0; i< nums.size(); i++){
            mp[nums[i]]++;
         }

         int maxi = 0;
         int sum = 0;

         for(auto it : mp){
            int key = it.second;
            maxi=max(maxi,key);
         }

         for(auto it : mp){
            if(it.second==maxi) sum = sum + it.second;
         }
         return sum;
    }
};