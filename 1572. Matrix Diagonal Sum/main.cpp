class Solution {//TC:O(N) SC:O(1)
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size() , ans =0;
        for(int i=0;i<n;i++) {
            ans+=mat[i][i];//primary diagonal
            if( i != n-i-1) ans+=mat[i][n-i-1];// secondary diagonal
        }
        return ans;
    }
};

//https://leetcode.com/problems/matrix-diagonal-sum/solutions/3498593/c-easy-2-line-code/
