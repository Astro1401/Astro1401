class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            int distinct = 0, maxFreq = 0;

            for (int j = i; j < n; j++) {
                int c = s[j] - 'a';

                if (cnt[c] == 0) distinct++;
                cnt[c]++;
                maxFreq = max(maxFreq, cnt[c]);

                int len = j - i + 1;

                if (maxFreq * distinct == len) {
                    res = max(res, len);
                }
            }
        }
        return res;
    }
};
