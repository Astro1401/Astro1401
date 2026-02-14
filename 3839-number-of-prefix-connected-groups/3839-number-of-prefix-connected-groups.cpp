class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp; 
        
        for(string w : words){
             if(w.length()>=k){
                 string pref = w.substr(0,k);
                 mp[pref]++;
             }
         }

        int groups = 0;

        for(auto it : mp){
            if(it.second>=2){
                groups++;
            }
        }
        return groups;
    }
};