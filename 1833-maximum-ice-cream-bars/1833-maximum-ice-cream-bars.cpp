class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        sort(costs.begin(),costs.end());
        int ans = 0;
        for(auto it : costs){
            if(it<=coins){
                ans++;
                coins = coins - it;
            }
        }
        return ans;
    }
};