class Solution {
public:
    int gcd(int &i , int &j){
         int gcdno = min(i,j);

         while(gcdno != 0){
            if(i%gcdno == 0 && j%gcdno == 0) return gcdno;
            gcdno--;
         }
         return 1;
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return gcd(nums[0],nums[nums.size()-1]);
    }
};