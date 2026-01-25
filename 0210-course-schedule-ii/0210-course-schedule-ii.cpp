class Solution {
private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], vector<int>& topo) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, topo))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        topo.push_back(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        // build graph: prereq → course
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        int vis[numCourses];
        int pathVis[numCourses];
        memset(vis, 0, sizeof(vis));
        memset(pathVis, 0, sizeof(pathVis));

        vector<int> topo;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, topo))
                    return {}; // cycle found
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};
