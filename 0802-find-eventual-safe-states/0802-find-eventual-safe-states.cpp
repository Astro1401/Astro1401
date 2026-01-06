class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& graph,
                  vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {

        vis[node] = 1;
        pathVis[node] = 1;
        safe[node] = 0;  // assume unsafe initially

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, graph, vis, pathVis, safe)) {
                    safe[node] = 0;
                    return true; // cycle found
                }
            }
            else if (pathVis[it]) {
                safe[node] = 0;
                return true; // cycle found
            }
        }

        // no cycle found from this node
        safe[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), safe(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, safe);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};
