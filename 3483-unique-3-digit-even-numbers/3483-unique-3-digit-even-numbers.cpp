class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Choose the units digit: must be even
        for (int last = 0; last <= 8; last += 2) {
            if (freq[last] == 0) continue;

            freq[last]--;

            // Choose the hundreds digit: cannot be 0
            for (int first = 1; first <= 9; first++) {
                if (freq[first] == 0) continue;

                freq[first]--;

                // Choose the tens digit
                for (int middle = 0; middle <= 9; middle++) {
                    if (freq[middle] > 0) {
                        ans++;
                    }
                }

                freq[first]++;
            }

            freq[last]++;
        }

        return ans;
    }
};