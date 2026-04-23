class Solution {
public:
    typedef long long ll;
    vector<long long> getDistances(vector<int>& arr) {
        vector<int> nums = arr;
        
        unordered_map<int ,ll> freq;
        unordered_map<int ,ll> sumfreq;
        int n = nums.size();
        
        vector<ll> ans(n,0);

        for(int i = 0; i<n; i++){
            ll frequ =  freq[nums[i]];
            ll sumo  =  sumfreq[nums[i]];

            ans[i] += frequ*i - sumo;

            freq[nums[i]] += 1;
            sumfreq[nums[i]] += i;  
        }

           freq.clear();
           sumfreq.clear();  

           for(int i = n-1; i>=0; i--){
            ll frequ =  freq[nums[i]];
            ll sumo  =  sumfreq[nums[i]];

            ans[i] += sumo - frequ*i ;

            freq[nums[i]] += 1;
            sumfreq[nums[i]] += i;  
        }
        return ans;
    }
};