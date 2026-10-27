class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n,'#'));
        int r = 0, c = 0;
        grid[r][c] = '.';

        bool goright = true;
        
       while(r<m-1 || c<n-1){
           if(goright){
               if(c+1<n) c++;
               else r++;
           }
           else{
               if(r+1<m) r++;
               else c++;
           }

           grid[r][c] = '.';
           goright = !goright;
       }
        return grid;
    }
};