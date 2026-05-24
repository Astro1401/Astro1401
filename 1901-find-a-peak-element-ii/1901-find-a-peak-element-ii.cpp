class Solution {
public:
    int findmax(vector<vector<int>> &mat , int m, int n , int col){
        int maxvalue = -1;
        int index = -1;

        for(int i = 0; i<m;i++){
            if(mat[i][col]>maxvalue){
                maxvalue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int s = 0;
        int e = n-1;
        
        while(s<=e){
            int mid = (s+e)/2;
            int maxrowindex = findmax(mat,m,n,mid);
            int left = mid - 1 >= 0 ? mat[maxrowindex][mid-1] : -1;
            int right = mid + 1 < n ? mat[maxrowindex][mid+1] : -1;

            if(mat[maxrowindex][mid] > left && mat[maxrowindex][mid] > right){
                return {maxrowindex, mid};
            }   

            else if(mat[maxrowindex][mid] < left) e = mid - 1;
            else s = mid + 1;
        } 
        return {-1,-1};
    }
};