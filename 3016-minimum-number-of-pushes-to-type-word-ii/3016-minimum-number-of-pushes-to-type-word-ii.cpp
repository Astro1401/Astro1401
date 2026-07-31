class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);

        for(int i = 0; i<word.length(); i++){
            arr[word[i]-'a']++;
        }
        sort(arr.begin(),arr.end());
        
        int cnt = 0;
        int multiplier = 1;
        int sum = 0;
        
        for(int i = 25; i>=0; i--){
            if(arr[i] == 0) continue;
            
            if(cnt==8){
                multiplier++;
                cnt = 0;
            }
            sum += arr[i] * multiplier;
            cnt++;
        }
        return sum;
    }
};