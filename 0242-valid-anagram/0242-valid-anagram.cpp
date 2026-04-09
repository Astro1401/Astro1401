class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        if(s.size() != t.size()) return false;
        for(int i = 0; i<s.size(); i++){
            mp1[s[i]]++;
        }

         for(int i = 0; i<s.size(); i++){
            mp2[t[i]]++;
        }
         
         for(int i = 0; i<t.size(); i++){
            if(mp2[s[i]] == mp1[s[i]]){
                continue;
            }

            else{
                return false;
            }
        }
        return true;
    }
};