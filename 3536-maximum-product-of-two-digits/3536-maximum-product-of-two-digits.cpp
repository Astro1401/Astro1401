class Solution {
public:
    int maxProduct(int n) {
        int temp = n;
        int firstmax = INT_MIN;
        int tmep2 = n;
        unordered_map<int,int> mp;
        
        while(tmep2>0){
            int digit = tmep2%10;
            mp[digit]++;
            tmep2 =  tmep2/10;
        }

        while(temp>0){
            int digit = temp%10;
            firstmax = max(digit,firstmax);
            temp = temp/10;
        }

        int secondmax = INT_MIN;
        while(n>0){
            int digit = n%10;
            if(digit > secondmax && digit == firstmax && mp[digit] > 1){
                secondmax = digit;
            }
            else if(digit>secondmax && digit < firstmax ){
                secondmax = digit;
            }
            n = n/10;
        }
       cout << firstmax;
       cout << secondmax;
        return firstmax*secondmax;
    }
};