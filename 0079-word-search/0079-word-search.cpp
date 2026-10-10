class Solution {
public:
    bool find(int i, int j, string &word, vector<vector<char>>& board, int idx){
        int m = board.size();
        int n = board[0].size();
        
        if(idx == word.length()){
            return true;
        }

        if(i<0 || j<0 || i>=m || j>=n || board[i][j] == '$') return false;

        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int k = 0; k<4; k++){
             int newr = i + dr[k];
             int newc = j + dc[k];

            if(find(newr,newc,word,board,idx+1)) return true;
        }

        board[i][j] = temp;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == word[0] && find(i,j,word,board,0)){
                    return true;
                }
            }
        }
        return false;
    }
};