class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevCount = 0, currCount = 1;
        int answer = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                currCount++;
            } else {
                answer += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }

        answer += min(prevCount, currCount);
        return answer;
    }
};
