class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0, b = 0;

        for(char c : s)
            if(c == 'a') a++;

        int ans = a;

        for(char c : s){
            if(c == 'a') a--;
            else b++;

            ans = min(ans, a + b);
        }

        return ans;
    }
};
