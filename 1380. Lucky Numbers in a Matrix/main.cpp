class Solution {//TC:O(N*M)  SC;O(M+N)
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m  = matrix[0].size();
        vector<int>minRows;
        set<int>maxCol;//will easy for finding the minimum of MAXIMUMS == maximum of MINIMUM
        vector<int>ans;
        for(vector<int>x:matrix) {
           minRows.push_back(*min_element(begin(x),end(x)));
        }
        for(int i = 0;i<m;i++) {//checking maximum for every COLUMN VECTOR ( M X 1)
            int maxi = 0;
            for(int j = 0;j<n;j++) {
                if(matrix[j][i] > maxi) {
                    maxi = matrix[j][i];
                }
            }
            maxCol.insert(maxi);
        }
        //finding the minimum of MAXIMUMS == maximum of MINIMUM
        // will return the number which obeys above condition
        for(auto num : minRows) {
            if(maxCol.find(num) != maxCol.end()) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
