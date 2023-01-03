class Solution { //TC;O(M*N)  SC:O(1)
public:
    int minDeletionSize(vector<string>& strs) {
        int m  = strs.size();//row size
        int n = strs[0].size(); //column size
        int deleteCount = 0;
        for(int j = 0;j<n;j++) {
            for(int i = 0;i<m-1;i++) {
                if(strs[i][j] > strs[i+1][j]) {
                    deleteCount++;
                    break;
                }
            }
        }
        return deleteCount;
    }
};
