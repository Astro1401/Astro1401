class DisjointSet {
public:
    vector<int> rankv, parent, sizev;

    DisjointSet(int n) {
        rankv.resize(n + 1, 0);
        parent.resize(n + 1);
        sizev.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rankv[ulp_u] < rankv[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rankv[ulp_v] < rankv[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rankv[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (sizev[ulp_u] < sizev[ulp_v]) {
            parent[ulp_u] = ulp_v;
            sizev[ulp_v] += sizev[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            sizev[ulp_u] += sizev[ulp_v];
        }
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        int cntextras = 0;

        for(auto it :connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u)==ds.findUPar(v)){
                  cntextras++;
            }
            else{
                ds.unionBySize(u,v);
            }

        }

        int cntc = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i]==i) cntc++;
        }

        int ans = cntc-1;
        if(cntextras>=ans) return ans;
        return -1;
    }
};