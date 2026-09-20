class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long cnt = 0;

        sort(intervals.begin(),intervals.end());
        vector<int> ans;

        for(auto it : intervals){
            ans.push_back(it[0]);
        }

        for(int i = 0; i<intervals.size(); i++){
            
            int end = intervals[i][1];
            int idx = upper_bound(ans.begin(), ans.end(), end) - ans.begin();
            cnt += idx - i - 1;
        }
        return cnt;
    }
};