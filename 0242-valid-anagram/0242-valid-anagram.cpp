class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> vis(26,0);

        for(int i = 0; i<s.length(); i++){
            vis[s[i] - 'a']++;
        }

        for(int i = 0; i<t.length(); i++){
            if(vis[t[i]-'a'] == 0) return false;
            else vis[t[i] - 'a']--;
        } 
        return true;
    }
};