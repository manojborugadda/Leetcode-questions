class Solution {//TC:O(N*M+K)
public:///SC:O(N*M)
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        unordered_map<int, pair<int, int>> map; // Corrected type to store row and column as a pair
        
        // Map each element in `mat` to its row and column indices
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                map[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rCnt(row, 0); // Row counts
        vector<int> cCnt(col, 0); // Column counts
        
        // Iterate through `arr` and update row/column counts
        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = map[arr[i]]; // Get row and column indices
            rCnt[r]++;
            cCnt[c]++;
            
            // Check if any row or column is completely painted
            if (rCnt[r] == col || cCnt[c] == row) {
                return i;
            }
        }
        
        return arr.size() - 1; // Fallback return value (problem guarantees this won't happen)
    }
};
