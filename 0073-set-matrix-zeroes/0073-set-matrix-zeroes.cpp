class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> indices;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0){
                      indices.push_back({i,j});
                }
            }
        }

        for(auto it : indices){
            int row = it.first;
            int col = it.second;
            int i = 0; int j = 0;
            while(j<n){
                matrix[row][j] = 0;
                j++;
            }

            while(i<m){
                matrix[i][col] = 0;
                i++;
            }
        }
    }
};