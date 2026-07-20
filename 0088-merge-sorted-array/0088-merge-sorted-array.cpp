class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int left;
         for(int i = m-1; i>0; i--){
            if(nums1[i] != 0 ){
                left = i;
                break;
            } 
         }
         int ram = left;

         int right = 0;

         while(left>=0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left],nums2[right]);
                left--; right++;
            }
            else break;
         }
         sort(nums1.begin(),nums1.begin()+ram+1);
         sort(nums2.begin(),nums2.end());
         int i = ram+1;
         int j = 0;
         while(j<n){
            nums1[i] = nums2[j];
            i++; j++; 
         }
    }
};