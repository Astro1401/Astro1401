class Solution {
public:
    double angleClock(int hour, int minutes) {
        double diff = minutes * 0.5;

        double hourmin = minutes*6 - (hour % 12) * 30.0 ;
        double result = abs(diff-hourmin);
        
        return min(result,360-result);
    }
};