class Solution {
public:
    int networkDelayTime(vector<vector<int>>& flights, int n, int src) {

        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        q.push({0, src});

        vector<int> dist(n + 1, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.top();
            q.pop();

            int cost = it.first;
            int node = it.second;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edw = it.second;

                if (cost + edw < dist[adjNode]) {
                    dist[adjNode] = cost + edw;
                    q.push({cost + edw, adjNode});
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