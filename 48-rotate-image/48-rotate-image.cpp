class Solution {  ///TC:O(M*N) SC:O(1) -- as we are not using Extra Space
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        relfect(matrix);
    }
        
        // Transpose the Matrix across the Diagonal
        void transpose(vector<vector<int>>& matrix){
            int n = matrix.size();
             for(int i = 0;i<n;i++){
                 for(int j = i;j<n;j++){
                        int temp = matrix[j][i];
                        matrix[j][i] = matrix[i][j];
                        matrix[i][j] = temp;
                    }
                }   
            }
        ///flipping the matrix over the Middle column of the Matrix
        void relfect(vector<vector<int>>& matrix){
            int n = matrix.size();
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n/2;j++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][n-j-1];
                    matrix[i][n-j-1] = temp;
                }
            }
        }
};