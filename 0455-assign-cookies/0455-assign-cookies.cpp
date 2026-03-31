class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         sort(g.begin(),g.end());
         sort(s.begin(),s.end());

         int m = g.size();
         int n = s.size();
         int l = 0;
         int r = 0;
         int cnt = 0;
         while(l<m && r<n){
            if(s[r]>=g[l]){
                 l++; r++; cnt++;
            }

            else{
                r++;
            }
         }
         return cnt;
    }
};