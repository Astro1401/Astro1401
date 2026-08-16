class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int x = target[0] , y = target[1];
        int mini = 1e9;
        int ind = 101;
        for(int i = 0; i<drones.size(); i++){
             int xi = drones[i][0];
             int yi = drones[i][1];
             int range = drones[i][2];

             int mandis = abs(xi - x) + abs(yi - y);
             if(mandis <= range){
                
                if(mandis < mini){
                    mini = mandis;
                    ind = i;
                } 
                
                else if(i<101 && ind == i){
                    ind = min(i,ind);
                }
             }
             else continue;
        }
        if(ind == 101) return -1;
        return ind;
    }
};