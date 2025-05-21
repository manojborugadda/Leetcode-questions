class Solution {//TC:O(N*M)  SC:O(1)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>s1,s2;
        int m = matrix.size();
        int n = matrix[0].size();
        //Saving i and j values of a Cell in the set1(saves i value), set2(saves j values) which are of value 0
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(matrix[i][j] == 0) {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }

        //inplace operation for those i,j cells with 0
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(s1.count(i) or s2.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }

        return;

    }
};
