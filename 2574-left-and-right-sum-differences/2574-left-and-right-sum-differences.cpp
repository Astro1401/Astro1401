class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> l(n,0);
        vector<int> r(n,0);
        vector<int> fin(n,0);

        for(int i = 0; i<n; i++){
            for(int j = i-1; j>=0; j--){
                l[i] += nums[j];
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                r[i] += nums[j];
            }
        }

        for(int i = 0; i<n; i++){
            fin[i] = abs(l[i] - r[i]);
        }
        
        return fin;
    }
};