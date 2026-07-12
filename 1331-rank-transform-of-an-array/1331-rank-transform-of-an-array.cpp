class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ram = arr;
        sort(ram.begin(),ram.end());
        int n = arr.size();
        vector<int> ans(n,0);

        unordered_map<int,int> mp;
        int j = 1;
        for(int i = 0; i<arr.size(); i++){
            if(mp[ram[i]]==0) mp[ram[i]] = j++;
        }

        for(int i = 0; i<arr.size(); i++){
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};