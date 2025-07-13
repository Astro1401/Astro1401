class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int m = nums1.size();
     int n = nums2.size();
     vector<int> nums(m+n);
     int i = 0;
     int j = 0;
     int k = 0;
     while(i<m && j<n){
 
     if(nums1[i]>=nums2[j]) 
     { nums[k]=nums2[j];
     j++;
     k++;
     }
       else{
        nums[k]=nums1[i];
        i++;
        k++;
       }
     }

     while(i<m){
        nums[k]=nums1[i];
        k++;
        i++;
     }

     while(j<n){
        nums[k]=nums2[j];
        k++;
        j++;
     }

     int low = 0;
     int high = nums.size()-1;

     int mid = (low+high)/2;

     if(nums.size()%2 != 0) return nums[mid];
     else{
        double ans = (nums[mid]+nums[mid+1])/2.0;
        return ans;
     }
      
    
    }
};