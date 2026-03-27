class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> temp = mat;

        k = k % n; 

        for(int i = 0; i < m; i++){
            for(int z = 0; z < k; z++){   // fix here
                if(i % 2 == 0){
                    // left shift
                    int first = temp[i][0];
                    for(int j = 0; j < n - 1; j++){
                        temp[i][j] = temp[i][j + 1];
                    }
                    temp[i][n - 1] = first;
                }

                else{
                    // right shift
                    int last = temp[i][n - 1];
                    for(int j = n - 1; j > 0; j--){
                        temp[i][j] = temp[i][j - 1];
                    }
                    temp[i][0] = last;
                }
            }
        }

        if(temp == mat) return true;

        return false;
    }
};