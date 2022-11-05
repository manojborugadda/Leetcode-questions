class Solution { //BACKTRACKING approach
public:
    
    //TC: O(r * c * (4 ^ w)), where r x c are the dimensions of the board.
    //W = length of the word
    bool exist(vector<vector<char>>& board, string word) {
         for(int i = 0;i<board.size();i++) {
            for(int j = 0;j<board[0].size();j++) {
                if(board[i][j] == word[0] and dfs(board,i,j,0,word)) {
                    return true;   
                }
            }
        }
        return false;
    }
    
    private:
        bool dfs(vector<vector<char>>& board,int i,int j,int index,string word) {
        if(index == word.length()) return true;
        if(i < 0 or j < 0 or i > board.size()-1 or j > board[0].size()-1 or word[index] != board[i][j]) {
            return false;
        }
        
            //mark as visited
        char temp  = board[i][j];
        board[i][j] = ' ';  //emptying that cell
            
        auto find  = dfs(board,i+1,j,index+1,word)  or
                    dfs(board,i-1,j,index+1,word)   or
                    dfs(board,i,j-1,index+1,word)   or
                    dfs(board,i,j+1,index+1,word);
            //backtrack
     board[i][j] = temp;
        return find;
    }
};