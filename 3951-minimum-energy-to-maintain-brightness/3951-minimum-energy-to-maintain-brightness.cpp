class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
       if(intervals.empty()) return 0;

       long long minbulbs = (brightness+2)/3;
        sort(intervals.begin(), intervals.end());

        long long totaltime = 0;
        int currentstart = intervals[0][0];
        int currentend = intervals[0][1];

        for(size_t i = 1; i< intervals.size(); i++){
            if(intervals[i][0] <= currentend){
                currentend = max(currentend, intervals[i][1]);
            }
            else{
                totaltime += (currentend - currentstart + 1LL);
                currentstart = intervals[i][0];
                currentend = intervals[i][1];
            }
        }
        totaltime += (currentend - currentstart + 1LL);

        return minbulbs * totaltime;
    }
};