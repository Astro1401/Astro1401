class Solution {
public:
    bool possible(vector<int>& nums , int mid , int threshold){
 
        int cnt = 0;
        int n = nums.size();

        for(int i = 0; i< n; i++){
            cnt += ceil((double)nums[i]/mid);
        }

        return cnt<=threshold;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mini= INT_MAX;
        int maxi= INT_MIN;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }

        int low = 1;
        int high = maxi;
        
        while(low<=high){
            int mid = (low+high)/2;

            if(possible(nums,mid,threshold)){
                high = mid - 1;
            }

            else{
                low = mid + 1;
        }
        }

        return low;
    }
};