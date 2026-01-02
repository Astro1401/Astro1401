class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Add all initially rotten oranges to queue and count fresh ones
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0; // No fresh oranges at start

        int minutes = 0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // Up, Down, Left, Right

        while(!q.empty()){
            int sz = q.size();
            bool rottedThisRound = false;

            for(int i = 0; i < sz; i++){
                auto [r, c] = q.front(); q.pop();

                for(auto &d : dirs){
                    int nr = r + d[0], nc = c + d[1];

                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2; // rot the fresh orange
                        q.push({nr,nc});
                        fresh--;
                        rottedThisRound = true;
                    }
                }
            }

            if(rottedThisRound) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
