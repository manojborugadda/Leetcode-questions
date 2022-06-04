class Solution {
private:
    vector<vector<string>> ans;
    vector<string> soln;
    
    bool is_safe(int &row, int &col, int &n){
        // Check if queen exists in same column
        for(int i = 0; i < row; i++)
            if (soln[i][col] == 'Q')
                return false;
        
        // Check if queen exists in top left diagonal
        for(int i = min(row, col); i >= 0; i--)
            if (soln[row-i][col-i] == 'Q')
                return false;
        
        // Check if queen exists in top right diagonal
        for(int i = min(row, n - col - 1) ; i >= 0; i--)
            if (soln[row-i][col+i] == 'Q')
                return false;
        
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        //soln = vector<string> (n, string(n, '.'));
        soln.resize(n, string(n, '.'));
        solve(0, n);
        return ans;
    }
    
    void solve(int row, int n){
        if(row == n){  // base condition
            ans.push_back(soln);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if (is_safe(row, i, n)){
                soln[row][i] = 'Q';
                solve(row + 1, n);
                soln[row][i] = '.';
            }
        }
    }
};