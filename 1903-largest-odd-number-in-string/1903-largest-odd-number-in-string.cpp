class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string res = "";
        int flag = 0,bharat = 0;
        if(num[n-1] % 2 == 1) return num;
     
        for(int i = n-1; i>=0; i--){
            
            if(num[i] % 2 == 0 && flag == 0) {
                flag = 1;
                continue;
            }
            else if(num[i] % 2 == 1 && flag){
                bharat = 1;
                res.push_back(num[i]);
                }

            else if(num[i] % 2 == 0 && flag == 1 && bharat){
                res.push_back(num[i]);
            }    
        }

        reverse(res.begin(),res.end());
        return res;
    }
};