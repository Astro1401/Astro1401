class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        
        for(int i = 0; i<n; i++){
          
           int mini = 1e9; int maxi = -1;
          
           for(int j = i; j<n; j++){
               if(nums[j] < mini) mini = nums[j];    
           }

           for(int j = i; j>=0; j--){
               if(nums[j] > maxi) maxi = nums[j];    
           }

           int stability = maxi - mini;

           if(stability <= k ) return i; 
        }

        return -1;
    }
};