class Solution {
public:
    // Custom comparator
    static bool cmp(int a, int b) {
        int bitsA = __builtin_popcount(a);
        int bitsB = __builtin_popcount(b);

        if(bitsA == bitsB)
            return a < b;        // tie -> smaller number first
        
        return bitsA < bitsB;    // fewer 1 bits first
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};