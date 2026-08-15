class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resultxor = 0;
        bool allzero = true;
        
        for(auto it: nums){
            resultxor = resultxor ^ it;

            if(it != 0) allzero = false;
        }

        if(allzero) return 0;

        return (resultxor==0) ? n-1 : n; 
    }
};