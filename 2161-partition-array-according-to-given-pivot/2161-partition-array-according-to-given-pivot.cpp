class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int small = 0 , equal = 0;
        vector<int> ans(nums.size());
        
        for(auto it : nums){
            if(it < pivot) small++;
            else if (it == pivot) equal++;
        }

        int i = 0;
        int j = small;
        int k = small + equal;

        for(int z = 0; z<nums.size(); z++){
             if(nums[z] < pivot) {
                ans[i] = nums[z];
                i++;
            }

             else if (nums[z] == pivot) {
                ans[j] = nums[z];
                j++;
             }

             else{
                ans[k] = nums[z];
                k++;
             }
        } 
        return ans;
    }
};