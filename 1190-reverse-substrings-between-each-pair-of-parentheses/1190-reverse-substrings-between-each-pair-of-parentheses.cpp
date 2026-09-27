class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        string res = "";

        for(auto it : s){
            if(it == '('){
                st.push(res.length());
            }

            else if(it == ')'){
                reverse(res.begin() + st.top(),res.end());
                st.pop();
            }
            else{
            res += it;
            }
        }
        return res;
    }
};