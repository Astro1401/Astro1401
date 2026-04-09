class Solution {
public:
    int maxDepth(string s) {
        int maxcnt = 0,cnt = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='('){
               cnt++;
               maxcnt = max(maxcnt,cnt);
            }
            else if(s[i] == ')') cnt--;
            } 
        return maxcnt;
    }
};