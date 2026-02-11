class Solution {
public:
    struct SegTree {
        int n;
        vector<int> mn, lazy;

        SegTree(int n): n(n) {
            mn.assign(4*n, 0);
            lazy.assign(4*n, 0);
        }

        void push(int node) {
            if (lazy[node] != 0) {
                for (int c : {node*2, node*2+1}) {
                    mn[c] += lazy[node];
                    lazy[c] += lazy[node];
                }
                lazy[node] = 0;
            }
        }

        void update(int node, int l, int r, int ql, int qr, int v) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                mn[node] += v;
                lazy[node] += v;
                return;
            }
            push(node);
            int m = (l+r)/2;
            update(node*2, l, m, ql, qr, v);
            update(node*2+1, m+1, r, ql, qr, v);
            mn[node] = min(mn[node*2], mn[node*2+1]);
        }

        int queryFirstZero(int node, int l, int r, int ql) {
            if (r < ql || mn[node] > 0) return -1;
            if (l == r) return l;
            push(node);
            int m = (l+r)/2;
            int left = queryFirstZero(node*2, l, m, ql);
            if (left != -1) return left;
            return queryFirstZero(node*2+1, m+1, r, ql);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, queue<int>> pos;

        for (int i = 0; i < n; i++)
            pos[nums[i]].push(i);

        SegTree st(n);

        auto sign = [&](int x) {
            return (x & 1) ? 1 : -1;
        };

        // initial contributions
        for (auto &it : pos) {
            int p = it.second.front();
            st.update(1, 0, n-1, p, n-1, sign(it.first));
        }

        int ans = 0;

        for (int l = 0; l < n; l++) {
            int r = st.queryFirstZero(1, 0, n-1, l);
            if (r != -1)
                ans = max(ans, r - l + 1);

            int x = nums[l];
            int s = sign(x);

            int p = pos[x].front();
            pos[x].pop();

            st.update(1, 0, n-1, p, n-1, -s);

            if (!pos[x].empty()) {
                int np = pos[x].front();
                st.update(1, 0, n-1, np, n-1, s);
            }
        }

        return ans;
    }
};
