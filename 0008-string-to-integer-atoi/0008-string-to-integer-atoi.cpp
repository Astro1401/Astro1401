class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip spaces
        while(i < n && s[i] == ' ') i++;

        // 2. Sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        long num = 0;

        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Overflow check
            if(num > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};