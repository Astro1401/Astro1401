class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
         
         string s = "";
         int q = sum/9;
         int r = sum%9;

         cout << r;
         cout << q;

         while(q){
            s.push_back('9');
            q--;
         }

         if(r != 0)s.push_back(r + '0');
        cout << s;
         if(s.size() > num) return "";
         if(s.size() < num){
            while(num - s.size()){
                s.push_back('0');
            }
         }
         
         return s;
    }
};