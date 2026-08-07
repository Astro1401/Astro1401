class Solution {
public:
    int ismultiple(int n){
        int multiple = 1;
        while(n){

        int digit = n%10;
        multiple = multiple*digit;
        n = n/10;
        }
        return multiple;
    }
    int smallestNumber(int n, int t) {
        while(n){
            if(ismultiple(n) % t == 0) return n;
            else n++;
        }
        return 0;
    }
};