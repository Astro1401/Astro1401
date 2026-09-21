class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i , int j , int prev , vector<vector<bool>> &visited){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size()) return;

        if(heights[i][j] < prev || visited[i][j]) return;

        visited[i][j] = true;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k = 0 ; k<4; k++){
            int newr = dr[k] + i;
            int newc = dc[k] + j;

            dfs(heights,newr,newc,heights[i][j], visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> p(m,vector<bool>(n,false));
        vector<vector<bool>> a(m,vector<bool>(n,false));
        
        for(int j = 0; j<n; j++){
            dfs(heights,0,j,INT_MIN,p);
            dfs(heights,m-1,j,INT_MIN,a);
        }

        for(int i = 0; i<m; i++){
            dfs(heights,i,0,INT_MIN,p);
            dfs(heights,i,n-1,INT_MIN,a);
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(p[i][j] && a[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};