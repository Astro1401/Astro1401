class Solution {
public:
    int revno(int i){
        int no = 0;
        while(i>0){
            int digit = i%10;
            i = i/10;
            no = no*10+digit;
        }
        return no;
    }
    int mirrorDistance(int n) {
        int ans = revno(n);

        return abs(n-ans);
    }
};