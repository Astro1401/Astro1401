class Solution {
public:
    int minPartitions(string n) {
        int aloo = 0;
        for(char it : n){
            aloo = max(aloo,it-'0');
        }
        return aloo;
    }
};