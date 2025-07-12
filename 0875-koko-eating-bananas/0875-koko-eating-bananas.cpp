class Solution {
public:
    int findmax(vector<int>&piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i<n; i++){
            maxi=max(piles[i],maxi);
        }
        return maxi;
    }
     long long totalho(vector<int>&piles , int ho){
         long long totalh=0;
         int n = piles.size();
         for(int i = 0; i<n; i++){
            totalh += ceil((double)piles[i]/(double)ho);
         }
         return totalh;

    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
      
        while(low<=high){
            int mid = (low + high)/2;
            long long totalh = totalho(piles,mid);
            if(totalh<=h){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};