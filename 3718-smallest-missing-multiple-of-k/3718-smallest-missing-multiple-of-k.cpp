class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(auto it : nums) mp[it]++;
        
        int t = 1;
        
        while(true){
            int n = k*t;
            if(mp.find(n) != mp.end()){  
                t++;
            }
            else return n;
        }

        return 0;
    }
};