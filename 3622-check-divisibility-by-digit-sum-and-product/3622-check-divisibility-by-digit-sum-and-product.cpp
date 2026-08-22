class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 , product = 1;
        int p = n;
        while(n>0){
            int digit = n%10;
            sum += digit;
            product *= digit;
            n = n/10; 
        }

        if(p%(sum+product) == 0) return true;
        return false;
    }
};