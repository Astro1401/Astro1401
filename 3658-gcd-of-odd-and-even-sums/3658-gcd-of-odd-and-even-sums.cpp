class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = 0;
        int evensum = 0;

        for(int i = 1; i <= n; i++){
           oddsum += 2 * i - 1;
           evensum += 2 * i;
        }
        
        int i = 1;
        int ans=0;
        while(i<=min(oddsum,evensum)){
            if(oddsum % i == 0 && evensum % i == 0){
               ans = i;
            }
            i++;
        }
        return ans;
    }
};