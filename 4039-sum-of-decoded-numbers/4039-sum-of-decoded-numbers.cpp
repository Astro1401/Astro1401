class Solution {
public:

    long long func(string &x, string &y) {
        long long a = stoll(x);
        long long b = stoll(y);

        long long ans = 1;
        long long mod = 1000000007;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % mod;
            }

            a = (a * a) % mod;
            b = b / 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        int ans = 0;
        long long mod = 1e9 + 7;
        
        for(int i = 0; i<nums.size(); i++){
            int width = nums[i] % 10;
            long long d = nums[i] / 10;

            string s = to_string(d);
            string x = s.substr(0,width);
            string y = s.substr(width);
            
            long long decoded = func(x, y);

            ans = (ans + decoded) % mod;
        }
        return ans;
    }
};