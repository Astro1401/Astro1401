class Solution {
public:
    void solve(int cnt, vector<string> &ans, string &s, int n){
        
        if(cnt == n){
            ans.push_back(s);
            return;
        }

        if(s.empty() || s.back() != '0' ){
            s.push_back('0');
            solve(cnt+1,ans,s,n);
            s.pop_back();
        }

        s.push_back('1');
        solve(cnt+1,ans,s,n);
        s.pop_back();
    }
    vector<string> validStrings(int n) {
        int cnt = 0;
        vector<string> ans;
        string s;

        solve(cnt,ans,s,n);
        return ans;
    }
};