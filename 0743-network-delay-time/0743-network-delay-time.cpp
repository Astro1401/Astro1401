class Solution {
public:
    int networkDelayTime(vector<vector<int>>& flights, int n, int src) {
        
        int K = n;   // dummy, only to keep your logic unchanged
        int dst = -1; // unused, kept so structure stays same
        
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int,int>>> q;
        // {steps, {node, dist}}
        q.push({0, {src, 0}});

        vector<int> dist(n + 1, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;

                if (cost + edw < dist[adjNode]) {
                    dist[adjNode] = cost + edw;
                    q.push({steps + 1, {adjNode, cost + edw}});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
