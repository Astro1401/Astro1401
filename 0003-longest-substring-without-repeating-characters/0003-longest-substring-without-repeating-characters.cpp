class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            vector<bool> visited(256, false);

            for(int j = i; j < n; j++) {
                if(visited[s[j]]) {
                    break;  // duplicate found → stop expanding
                }

                visited[s[j]] = true;
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};
