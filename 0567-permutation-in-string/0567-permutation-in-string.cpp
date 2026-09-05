class Solution {
public:
    bool isfreqsame(vector<int> &freq,vector<int> &winfreq){
        for(int i = 0; i<26; i++){
            if(freq[i] != winfreq[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);

        for(int i = 0; i<s1.length(); i++){
           freq[s1[i] - 'a']++;
        }

        int winsize = s1.length();

        for(int i = 0; i<s2.length(); i++){
            int winidx = 0; int idx = i;

            vector<int> winfreq(26,0);
            
            while(winidx < winsize && idx < s2.length()){
                winfreq[s2[idx] - 'a']++;
                winidx++; idx++;
            }

        if(isfreqsame(freq,winfreq)) return true;    
        }
        return false;
    }
};