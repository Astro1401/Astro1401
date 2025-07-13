class Solution {
public:
    int check (vector<int> &nums , int aloo){
        int n = nums.size();
        int students=1;
        int pages = 0;

        for(int i = 0; i<n; i++){
            if(pages+nums[i]>aloo){
                students++;
                pages = nums[i];
            }

            else{
                pages += nums[i];
            }
        }
        return students;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = (low+high)/2;
            int ramu = check(nums,mid);
            if(ramu<=k){
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }

        return low;
    }
};