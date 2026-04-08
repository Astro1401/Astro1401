class Solution {
public:
    string reverseWords(string s) {
        string res = "", temp = "";
        int n = s.size();
        int flag = 0;

        for(int i = n-1; i >= 0; i--){
            
            if(s[i] == ' ' && flag == 0) continue;
            
            if(s[i] == ' ' && flag == 1) {
                reverse(temp.begin(), temp.end());   // ✅ reverse only word
                if(!res.empty()) res += " ";
                res += temp;
                temp = "";
                flag = 0;
                continue;
            }

            if(s[i] != ' ') {
                flag = 1;
                temp.push_back(s[i]);
            }
        }

        // last word
        if(!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if(!res.empty()) res += " ";
            res += temp;
        }

        return res;
    }
};