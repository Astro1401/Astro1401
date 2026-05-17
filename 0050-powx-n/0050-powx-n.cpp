class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double ans = 1;

        if(N < 0) {
            N = -N;
        }
        while(N){
            if(N%2){
                ans = ans*x;
                N = N-1;
            }

            else{
                x = x*x;
                N = N/2;
            }
        }

        if(n<0) ans = 1/ans;
        return ans;
    }
};