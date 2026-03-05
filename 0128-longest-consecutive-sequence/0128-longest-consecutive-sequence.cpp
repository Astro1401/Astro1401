class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        int longest = 1;
        unordered_set<int> st;
        for(auto it : nums){
           st.insert(it);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
    
                while(st.find(it+1) != st.end()){
                    cnt++;
                    it++;
                }

                longest = max(longest,cnt);
            }
        }

        return longest;
    }
};