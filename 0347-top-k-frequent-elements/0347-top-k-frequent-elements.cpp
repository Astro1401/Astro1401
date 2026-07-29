class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(auto it : nums){
           mp[it]++;
        } 

        vector<vector<int>> bucket(n+1);

        for(auto it : mp){
            int freq = it.second;
            int val = it.first;
 
            bucket[freq].push_back(val);
        }

        vector<int> result;

        for(int i = n; i>=0; i--){
           if(bucket[i].size() == 0) continue;

           while(bucket[i].size() > 0 && k>0){
            result.push_back(bucket[i].back());
            bucket[i].pop_back();
            k--;
           }
        }
        return result;
    }
};