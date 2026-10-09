class Solution {
public:
    void findans(int ind, vector<int>& arr, int target, vector<vector<int>> &ans, vector<int> &ds,int k,int cnt){
        
        if(cnt>k) return;

        if(cnt == k && target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = ind; i<arr.size(); i++){
            if(i!=ind && arr[i] == arr[i-1])continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findans(i+1,arr,target-arr[i],ans,ds,k,cnt+1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int cnt = 0;

        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        findans(0, candidates, n, ans, ds, k, 0);
        return ans;
    }
};