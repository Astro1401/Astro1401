class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<int> ans;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans.push_back(grid[i][j]);
            }
        }

        sort(ans.begin(),ans.end());
        int k = ans.size();
        int target = ans[k/2];  
        
        for(int i = 0; i<k; i++){
            if(ans[i]%x != target%x){
                return -1;
            }

            result += abs(target-ans[i])/x;
        }
       return result;
    }
};