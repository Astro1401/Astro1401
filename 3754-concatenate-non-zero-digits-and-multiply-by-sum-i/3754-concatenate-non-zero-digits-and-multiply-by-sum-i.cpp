class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long no = 1;
        long long final = 0;

        while (n != 0) {
            int digit = n % 10;

            if (digit != 0) {
                final += 1LL * digit * no;
                no *= 10;
            }

            sum += digit;
            n /= 10;
        }

        return final * sum;
    }
};