class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i = 0; i<s.length(); i++){
            
            int p = abs((s[i] - 'a') - 26);
            ans += p*(i+1);
            
        }

        return ans;
    }
};