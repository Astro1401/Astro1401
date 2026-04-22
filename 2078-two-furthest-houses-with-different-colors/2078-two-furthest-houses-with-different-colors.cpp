class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi = INT_MIN;

        for(int i = 0; i<colors.size(); i++){
            for(int j = i; j<colors.size(); j++){
                int dist = 0;
                if(colors[i] != colors[j]){
                    dist = abs(i-j);
                    maxi = max(maxi,dist);
                }
            }
        }
        return maxi;
    }
};