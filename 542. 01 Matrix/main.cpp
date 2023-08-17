class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<P>q;
        for(int i = 0;i<mat.size();i++) {
            for(int j = 0;j<mat[0].size();j++) {
                if(mat[i][j] == 0) {
                    q.push(make_pair(i,j));
                }else {
                    mat[i][j] = -1;
                }
            }
        }

        vector<vector<int>>dir = {{0,1},{-1,0},{1,0},{0,-1}};
        
        int level = 0;
        while(!q.empty()) {
            P pair = q.front();
            q.pop();
            for(auto &d : dir) {
                int i = d[0]+ pair.first;
                int j  = d[1] + pair.second;
                if(i >= 0 and i < mat.size() and j >= 0 and j < mat[0].size() and mat[i][j] == -1 ) {
                    q.push({i,j});
                    mat[i][j] = 1 + mat[pair.first][pair.second];
                }
            }
        }
        return mat;
    }
};
