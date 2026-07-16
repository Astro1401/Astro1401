class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixgcd(n,0);

        int maxi = INT_MIN;

        for(int i = 0; i<n; i++){
           maxi = max(maxi,nums[i]);
           prefixgcd[i] = __gcd(maxi,nums[i]);
        }

        sort(prefixgcd.begin(),prefixgcd.end());
           
        int s = 0; int e = n-1;
        long long sum = 0;
        while(s<e){
                sum += __gcd(prefixgcd[s],prefixgcd[e]);
                s++;
                e--;
        }
        return sum;
    }
};