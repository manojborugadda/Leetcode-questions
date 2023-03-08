class Solution { // T: O(R * C * (4 ^ w)), where R ,C are the dimensions of the board.
    //W -->length of the word
    public boolean exist(char[][] board, String word) {
        //int m = board.length , n = board[0].length;
        for(int i = 0;i<board.length;i++) {
            for(int j = 0;j<board[0].length;j++) {
                if(board[i][j] == word.charAt(0) && dfs(board,i,j,0,word)) {
                    return true;   
                }
            }
        }
        return false;
    }
    
    private boolean dfs(char[][] board,int i,int j,int index,String word) {
        if(index == word.length()) return true;
        if(i < 0 || 
           j < 0 ||
           i > board.length-1 ||
           j > board[0].length-1 ||
           word.charAt(index) != board[i][j]) {
            return false;
        } 
        
        char temp  = board[i][j];//mark as visited
        board[i][j] = ' ';  //
        var find  = dfs(board,i+1,j,index+1,word) ||
                    dfs(board,i-1,j,index+1,word) ||
                    dfs(board,i,j-1,index+1,word) ||
                    dfs(board,i,j+1,index+1,word);
     board[i][j] = temp;//backtrack
        return find;
    }
}
