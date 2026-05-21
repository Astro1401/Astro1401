class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(auto it : arr1){
            while(it>0){
                st.insert(it);
                it = it/10;
            }
        }
        int ans = 0; 
        for(auto it : arr2){
            while(it>0){
                if(st.count(it)){
                   ans = max(ans,(int)log10(it)+1);
                   break;
                }
                it = it/10;
            }
        }
        return ans;
    }
};