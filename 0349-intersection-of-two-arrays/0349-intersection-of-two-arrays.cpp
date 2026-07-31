class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n2>n1) intersection(nums2,nums1);
        
        unordered_map<int,int> mp;
        vector<int> result;

            for(auto it : nums1){
                mp[it]++;
            }

            for(int i = 0; i<n2; i++){
                if(mp.find(nums2[i]) != mp.end() && mp[nums2[i]] != -1) {
                    result.push_back(nums2[i]);
                    mp[nums2[i]] = -1;
                }
            }
        return result;
    }
};