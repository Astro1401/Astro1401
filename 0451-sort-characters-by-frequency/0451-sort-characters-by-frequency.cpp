class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c : s) mp[c]++;

        vector<string> bucket(s.size()+1);

        for(auto &p : mp){
            bucket[p.second] += string(p.second, p.first);
        }

        string res = "";
        for(int i = s.size(); i >= 0; i--){
            res += bucket[i];
        }

        return res;
    }
};