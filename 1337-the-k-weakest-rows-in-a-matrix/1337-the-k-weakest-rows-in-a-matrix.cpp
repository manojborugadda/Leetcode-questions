class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int,int>>m;
    vector<int>ans;
        
        for(int i=0;i<mat.size();i++){
            int c = count(begin(mat[i]),end(mat[i]),1);
           m.push_back(make_pair(c,i));
           
        }
        
        sort(m.begin(),m.end());
        for(int i=0;i<k;i++){
            ans.push_back(m[i].second);
        }
        
        return ans;
    }
};