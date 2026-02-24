class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;
        for(int i = 0; i<31; i++){
            int ch = ans & 1;
            ans = ans >> 1;
            if(ch == 1) cnt++;
        }

        return cnt;
    }
};