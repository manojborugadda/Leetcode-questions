https://leetcode.com/problems/word-search/discuss/349677/Java-or-Time-and-Memory-beats-100-or-Backtracking-template
​
```
public boolean exist(char[][] board, String word) {
for(int i = 0; i < board.length; i++){
for(int j = 0; j < board[0].length; j++){
if(board[i][j] == word.charAt(0) && dfs(board,i,j,0, word)){
return true;
}
}
}
​
return false;
}
​
​
private boolean dfs(char[][] board, int i, int j, int index, String word){
if(index == word.length())
return true;
​
if(i <0 || i>board.length-1 || j<0 || j>board[0].length-1)
return false;
​
if(word.charAt(index) != board[i][j])
return false;