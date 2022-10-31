class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 1;i<matrix.size();i++) {
            for(int j = 1;j<matrix[0].size();j++) {
                //if( i == 0 and j == 0) continue;
                if(matrix[i][j] != matrix[i-1][j-1]) return false;
               
            }
        }
        return true;
    }
};