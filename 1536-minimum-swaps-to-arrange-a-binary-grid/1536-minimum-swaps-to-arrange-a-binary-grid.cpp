class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);
        
        // Step 1: Count trailing zeros for each row
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            zeros[i] = count;
        }
        
        int swaps = 0;
        
        // Step 2: Greedy arrangement
        for(int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;
            
            // Find a valid row
            while(j < n && zeros[j] < required) {
                j++;
            }
            
            if(j == n) return -1;  // Not possible
            
            // Bubble up
            while(j > i) {
                swap(zeros[j], zeros[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};