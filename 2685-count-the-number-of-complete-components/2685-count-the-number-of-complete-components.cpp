class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis, int &e, int &v){
          vis[node] = 1;
          v++;
          e += adj[node].size();
          for(auto it : adj[node]){
            if(vis[it] != 1){
                dfs(it,adj,vis,e,v);
            }
          }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n,-1);
        int result = 0;
        vector<vector<int>> adj(n);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i<n; i++){
                int v = 0;
                int e = 0;
            if(vis[i] != 1){
                int v = 0;
                int e = 0;
                dfs(i,adj,vis,e,v);
                if((v*(v-1))/2 == e/2) result++;
            }
        }
        return result;
    }
};