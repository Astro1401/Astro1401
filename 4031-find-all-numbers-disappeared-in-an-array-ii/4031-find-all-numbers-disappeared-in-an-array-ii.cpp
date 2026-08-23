class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }

        vector<int> b;

        for(int i = lower; i<=upper; i++){
            if(mp.find(i) != mp.end()) continue;
            else b.push_back(i);
        }
        
        vector<vector<int>> ans;
        if(b.empty()) return ans;
       
        int l = 0; int r = 1;

        while(r<b.size()){
           if(b[r-1] + 1 == b[r]){
             r++;
           }
           
           else{
            ans.push_back({b[l],b[r-1]});
            l = r;
            r++;
           }
            
        }

        ans.push_back({b[l], b[r-1]});
        
        return ans;
    }
};