class Solution {
private:
    int ans = 0; // answer variable
    vector<vector<bool>>soln; // temporary chessboard 
    
    bool is_safe(int &row,int &col,int&n){
         // Check if queen exists in same column
        for(int i = 0; i < row; i++){
            if (soln[i][col] == true){
                return false;
            }
        }
        
        // Check if queen exists in top left diagonal
        for(int i = min(row, col); i >= 0; i--){
            if (soln[row-i][col-i] == true){
                return false;
            }
        }
        
        // Check if queen exists in top right diagonal
        for(int i = min(row, n - col - 1) ; i >= 0; i--){
            if (soln[row-i][col+i] == true){
                return false;
            }
        }
        return true;
    }

public:
    int totalNQueens(int n) {
        soln.resize(n,vector<bool>(n,false));
        solve(0,n);
        return ans;
    }
    
    void solve(int row,int n){
        if(row==n){
            ans++;
            return;
        }
        
        for(int i = 0;i<n;i++){
            if(is_safe(row,i,n)){
                soln[row][i]=true;
                solve(row+1,n);
                soln[row][i] = false;
            }
        }
    }
};