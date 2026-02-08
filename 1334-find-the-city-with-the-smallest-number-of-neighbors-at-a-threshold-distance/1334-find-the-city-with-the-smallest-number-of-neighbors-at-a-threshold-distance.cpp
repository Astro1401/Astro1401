class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int city = -1;
        int minCount = 1e9;

        for (int i = 0; i < n; i++) {

            queue<pair<int,int>> q;
            vector<int> dist(n, 1e9);

            q.push({i, 0});
            dist[i] = 0;

            while (!q.empty()) {
                auto it = q.front();
                q.pop();

                int node = it.first;
                int cost = it.second;

                for (auto iter : adj[node]) {
                    int adjNode = iter.first;
                    int edw = iter.second;

                    if (cost + edw < dist[adjNode]) {
                        dist[adjNode] = cost + edw;
                        q.push({adjNode, cost + edw});
                    }
                }
            }

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= minCount) {
                minCount = count;
                city = i;
            }
        }

        return city;
    }
};
