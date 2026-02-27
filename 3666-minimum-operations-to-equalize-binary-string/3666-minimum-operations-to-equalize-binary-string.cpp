class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int Z = 0;

        for(char c : s)
            if(c == '0') Z++;

        if(Z == 0) return 0;
        if(k > n) return -1;

        int t = (Z + k - 1) / k;   // ceil(Z/k)

        // adjust parity
        while(t * k < Z || (t * k) % 2 != Z % 2) {
            t++;
            if(t > n + 5) return -1;  // safety bound
        }

        return t;
    }
};