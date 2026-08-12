class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        while(true){
            sum = 0;
            if(n<10 && (n==1 || n==7)){
                return true;
            }
            else if(n<10) return false;

            else {
                while(n>0){
                int digit = n%10;
                sum += digit*digit;
                n = n/10;
                }
                n = sum;
            }
        }
        return false;
    }
};