class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i< word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                mp[word[i]]++;
            }
        }
                      
        for(int i = 0; i<word.size(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                mp[word[i]]++;
                char ch = tolower(word[i]);
                if(mp[ch]>0 && mp[word[i]]<=1) count++;
            }
        }
        return count;
    }
};