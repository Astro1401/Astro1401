class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int maxlen = 0;
        int l = 0;
        int maxFreq = 0;

        for(int r = 0; r<s.length(); r++){
           mp[s[r]]++;
           
           maxFreq = max(maxFreq, mp[s[r]]);

           while((r - l + 1) - maxFreq > k){
             mp[s[l]]--;
             l++;
           }

           maxlen = max(maxlen , r - l + 1);
        }

        return maxlen;
    }
};