class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         
         int m = isWater.size();
         int n = isWater[0]. size();

         vector<vector<int>> dis(m, vector<int>(n,0));
         vector<vector<int>> vis(m, vector<int>(n,0));

         queue<pair<pair<int,int>,int>> q;

         for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(isWater[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }

                else {
                    vis[i][j] = 0;
                }
            }
         }

         int dr[] = {-1,0,1,0};
         int dc[] = {0,1,0,-1};

        while(!q.empty()){
 
        int i = q.front().first.first;
        int j = q.front().first.second;
        int steps = q.front().second;

        q.pop();
        dis[i][j] = steps;

        for(int k = 0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nr < m && nc >=0 && nc < n && vis[nr][nc] == 0){
                vis[nr][nc] = 1;
                q.push({{nr,nc},steps+1});
            }
        }
    }
       return dis;
    }
};