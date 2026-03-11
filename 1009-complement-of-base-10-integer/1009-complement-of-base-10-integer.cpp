class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int temp = n;
        int bits = 0;
        while(temp>0){
            temp  = temp>>1;
            bits++;
        }
        int ans = n ^ ((1<<bits) - 1);
        return ans;
    }
};