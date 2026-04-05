class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int i = 0; int j = 0;
           for(int k = 0; k<n; k++){
              if(moves[k] == 'U') i--;

              else if(moves[k] == 'D') i++;

              else if(moves[k] == 'L') j--;

              else if(moves[k] == 'R') j++;
           }
        

        return (i == 0 && j == 0);
    }
};