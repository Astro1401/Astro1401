class Solution {
public:
    int passwordStrength(string password) {
        int strength = 0;
        unordered_set<char> st;

        for (char ch : password) {

            // skip duplicate character
            if (st.count(ch)) continue;

            st.insert(ch);

            if (ch >= 'a' && ch <= 'z') {
                strength += 1;
            }

            else if (ch >= 'A' && ch <= 'Z') {
                strength += 2;
            }

            else if (ch >= '0' && ch <= '9') {
                strength += 3;
            }

            else if (ch == '!' || ch == '@' ||
                     ch == '#' || ch == '$') {
                strength += 5;
            }
        }

        return strength;
    }
};