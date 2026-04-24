class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0; int right = 0; int uscore = 0;
        
        for(int i = 0; i<moves.size(); i++){
            if(moves[i] == 'L') left++;
            if(moves[i] == 'R') right++;
            if(moves[i] == '_') uscore++;
        }

        int dist = abs(left-right);

        return uscore+dist;
    }
};