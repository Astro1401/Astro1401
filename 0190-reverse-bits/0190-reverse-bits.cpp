class Solution {
public:
    int reverseBits(int n) {
         uint32_t ans = 0;
        
        for(int i = 0; i < 32; i++) {
            ans = ans << 1;        // make space
            ans = ans | (n & 1);   // add last bit of n
            n = n >> 1;           // move to next bit
        }
        
        return ans;
    }
};