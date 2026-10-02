class Solution {
public:
    void solve(int open, int close, string &curr, vector<string> &result, int n){
        
        if(curr.size() == 2*n){
            result.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            solve(open+1,close,curr,result,n);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            solve(open,close+1,curr,result,n);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> result;

        int open = 0;
        int close = 0;

        solve(open,close,curr,result,n);

        return result;
    }
};