class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = 1;
        int evensum = 0;

        for(int i = 0; i<n; i++){
            oddsum += 2;
            evensum += 2;
        }
        int i = 1;
        int ans;
        while(i<=min(oddsum,evensum)){
            if(i%oddsum == 0 && i%evensum == 0){
                ans = i;
                i++;
            }
            i++;
        }
        return ans;
    }
};