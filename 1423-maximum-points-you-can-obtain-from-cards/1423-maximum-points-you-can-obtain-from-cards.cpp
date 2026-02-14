class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum =  0;
        for (int i = 0; i<k; i++){
            leftsum = leftsum + cardPoints[i];
        }
        int maxlen = leftsum;
        int rightsum = 0;
        int rightindex = cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            
            leftsum = leftsum-cardPoints[i];
            rightsum = rightsum + cardPoints[rightindex];
            rightindex--;
            maxlen = max(maxlen,leftsum+rightsum);
        }
        return maxlen;
    }
};