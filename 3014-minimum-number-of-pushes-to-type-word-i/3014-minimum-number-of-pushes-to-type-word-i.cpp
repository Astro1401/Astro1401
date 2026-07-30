class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int cnt = 0;
        int multiplier = 1;
        
        while(n>0){
           if(n >= 8){
             n -= 8;
             cnt += multiplier*8;
           }

           else{
             cnt += multiplier*n;
             n = 0;
           }
           
           multiplier++;
        }
        return cnt;
    }
};