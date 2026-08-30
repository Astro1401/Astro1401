class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
           if (mp.find(nums[i]) == mp.end()) {
              mp[nums[i]] = {i, i, 1};
           }
       
           else {
              mp[nums[i]][1] = i; 
              mp[nums[i]][2]++;   
           }
        }
        
        for(auto it : mp){
            if(it.second[1] - it.second[0] + 1 == it.second[2]) ans++;
        }
        
        return ans;
    }
};