class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int flag = 0;

        for(auto it: nums1) if(it % 2 == 1) flag = 1;

        if(flag == 0) return true;

        sort(nums1.begin(),nums1.end());

        if(nums1[0] % 2 == 0) return false;

        return true;
    }
};