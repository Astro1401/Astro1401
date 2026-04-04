class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (n == 0) return "";

        int cols = n / rows;
        string ans = "";

        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                ans += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        // remove trailing spaces
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};