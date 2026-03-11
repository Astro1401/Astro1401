class Solution {
public:
    int findComplement(int num) {
        long long int temp = num;
        long long int bits = 0;

        while(temp>0){
            temp = temp>>1;
            bits++;
        }
        long long int ans = num ^ ((1LL<<bits)-1);
        return ans;
    }
};