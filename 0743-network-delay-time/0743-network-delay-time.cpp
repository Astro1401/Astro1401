class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int,int>>> q;
        // {stops, {node, cost}}
        q.push({0, {k, 0}});

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node  = it.second.first;
            int cost  = it.second.second;

            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int edw     = iter.second;

                if (cost + edw < dist[adjNode]) {
                    dist[adjNode] = cost + edw;
                    q.push({stops + 1, {adjNode, cost + edw}});
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
