class Solution {
public:
    int countPrimes(int n) {
        vector <int> prime (n+1,true);
       if (n <= 0) return 0;
        prime[0]=false;
        prime[1]=false;
        int cnt = 0;
        for(int i=2; i<n; i++){
            if(prime[i]){
             cnt++;
            }
            for(int j=2*i;j<n; j=j+i){
                prime[j]=0;
            }
        } 
        return cnt;
    }
};