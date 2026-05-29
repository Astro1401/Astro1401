class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto it : nums){
            int sum = 0;
            while(it>0){
                int digit = it%10;
                sum = sum + digit;
                it = it/10;
            }
            mini = min(mini,sum);
        }
        return mini;
    }
};