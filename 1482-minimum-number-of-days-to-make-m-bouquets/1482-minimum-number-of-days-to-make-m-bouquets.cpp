class Solution {
public:
    bool possible(vector<int> &bloomDay , int day , int m , int k)
    {
  
       int n = bloomDay.size();
       int cnt = 0;
       int bookie=0;

        for(int i = 0; i<n; i++){
 
         if(bloomDay[i]<=day) cnt++;
          
        else{
            bookie += (cnt/k);
            cnt=0;
        }

        }

         bookie += (cnt/k);
        return bookie >= m;


    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll *k * 1ll;
        int n = bloomDay.size();
        if(val>n) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i<n; i++){
            maxi = max(maxi,bloomDay[i]);
            mini = min(mini,bloomDay[i]);
        }   
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = (high + low)/2;

            if(possible(bloomDay,mid,m,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};