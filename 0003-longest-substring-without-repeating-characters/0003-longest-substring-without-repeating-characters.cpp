class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                
                // Check substring from i to j
                bool visited[256] = {false};
                bool hasDuplicate = false;

                for(int k = i; k <= j; k++) {
                    if(visited[s[k]]) {
                        hasDuplicate = true;
                        break;
                    }
                    visited[s[k]] = true;
                }

                if(!hasDuplicate) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
