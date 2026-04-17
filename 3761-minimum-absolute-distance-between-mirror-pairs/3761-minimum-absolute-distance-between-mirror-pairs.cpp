class Solution {
public:
    int revno(int x){
        int digit = 0;
        while(x > 0){
            digit = digit * 10 + (x % 10);
            x /= 10;
        }
        return digit;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // value -> index
        int n = nums.size();
        int mini = 1e9;

        for(int i = n - 1; i >= 0; i--){
            int rev = revno(nums[i]);

            if(mp.count(rev)){
                mini = min(mini, mp[rev] - i);
            }

            mp[nums[i]] = i; // store current index
        }

        return (mini == 1e9) ? -1 : mini;
    }
};