class Solution {
public:
    static int getsum(int n){
       int sum = 0;
       while(n){
          int digit = n%10;
          sum += digit;
          n = n/10;
       }
       return sum;
    }
    static bool comp(int a , int b){
        int d1 = getsum(a);
        int d2 = getsum(b);

        if(d1 != d2) return d1<d2;

        return a < b; 
    }
    int minSwaps(vector<int>& nums) {
        
        vector<int> after = nums;
        sort(after.begin(),after.end(),comp);

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }

        int swap = 0;

        for(int i = 0; i < nums.size(); i++){
            int expec = after[i];
            int actual = nums[i];

            if(expec == actual) continue;

            int idx = mp[expec];

            nums[i] = expec;
            nums[idx] = actual;

            mp[expec]= i;
            mp[actual] = idx;

            swap++;

        }

        return swap;

    }
};