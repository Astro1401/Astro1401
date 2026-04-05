class Solution {
public:
    bool comp(string &s1, string &s2){
       if(s1.size() != 1 + s2.size()) return false;
       int i = 0;
       int j = 0;

       while(i<s1.size()){
         if(s1[i] == s2[j]){
            i++;
            j++;
         }
         else{
            i++;
         }
       }
       if(i == s1.size() && j == s2.size()) return true;
       return false;

    }
   static bool com(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),com);
        int n = words.size();
        int maxi = 1;
        
        vector<int> dp(n,1);
        
        for(int i = 0; i<n; i++){
            for(int j=0; j<i;j++){
                if(comp(words[i],words[j]) && 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }

            if(dp[i]>maxi) maxi = dp[i];
        }
        return maxi;
    }
};