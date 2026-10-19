class Solution {
private:
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int cnt) {
        int n = grid.size();

        if (i == n-1 && j == n-1) return true;

        vis[i][j] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k = 0; k<4; k++){
            int nr = dr[k] + i;
            int nc = dc[k] + j;

            if(nr>=0 && nr<n && nc>=0 && nc<n &&
               !vis[nr][nc] && grid[nr][nc] <= cnt){
                if(dfs(nr, nc, grid, vis, cnt)) return true;
            }
        }

        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int time = -1;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                time = max(time, grid[i][j]);
            }
        }

        int cnt = grid[0][0];

        while(cnt <= time){
            vector<vector<int>> vis(n, vector<int>(n, 0));

            if(dfs(0, 0, grid, vis, cnt)){
                return cnt;
            }

            cnt++;
        }

        return time;
    }
};