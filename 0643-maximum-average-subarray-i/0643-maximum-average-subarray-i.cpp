class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        double avg = -1e9;
        int size = 0;
        double sum = 0;
        
        for(int j = 0; j < n; j++){
            
            size++;
            sum += nums[j];
           
           if(size == k){
              double ans = sum/k;
              avg = max(avg,ans);
              sum -= nums[i];
              i++;
              size--;
           } 
             
        }

        return avg;
    }
};