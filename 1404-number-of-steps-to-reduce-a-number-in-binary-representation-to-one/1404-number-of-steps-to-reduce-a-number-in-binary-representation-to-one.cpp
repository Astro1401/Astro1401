class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;

        while (s != "1") {

            // If last bit is 1 → odd
            if (s.back() == '1') {
                // add 1 to binary string
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }

                if (i < 0) {
                    s = '1' + s;
                } else {
                    s[i] = '1';
                }

                cnt++;
            }
            else {
                // even → divide by 2 (remove last bit)
                s.pop_back();
                cnt++;
            }
        }

        return cnt;
    }
};