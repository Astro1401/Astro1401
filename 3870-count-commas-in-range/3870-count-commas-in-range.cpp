class Solution {
public:
    int countCommas(int n) {
        
        int cnt = 0; 
        int q = n;

        while(n>0){
            n = n/10;
            cnt++;
        }

        if(cnt < 4) return 0;
        int ans = q - 1000 + 1;
        return ans;

    }
};