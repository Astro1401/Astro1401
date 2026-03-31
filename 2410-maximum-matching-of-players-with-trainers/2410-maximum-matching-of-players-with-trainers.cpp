class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());

        int l = 0, r = 0, cnt = 0;
        int m = players.size();
        int n = trainers.size();

        while(l<m && r<n){
            if(trainers[r]>=players[l]){
                l++; r++; cnt++;
            }

            else{
                r++;
            }
        }
        return cnt;
    } 
};