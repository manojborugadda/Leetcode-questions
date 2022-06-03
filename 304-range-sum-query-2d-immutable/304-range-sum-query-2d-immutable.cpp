class NumMatrix {
public:   /// O(n*m)
    vector<vector<int>>v;//create a vector for prefix sum 

NumMatrix(vector<vector<int>>& mat) {
    
    int n=mat.size(),m=mat[0].size();//size of matrix n*m
    
    v.resize(n+1,vector<int>(m+1,0));//resize the prefix vector as size of matrix vector + 1 in row and column for handling base cases 
    //Also mark all elements as zero
    
    //store the prefix sum in vector v
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=m;j++){
            v[i][j]=v[i-1][j]+v[i][j-1]+mat[i-1][j-1]-v[i-1][j-1];
        }
    }
}

//TC:O(1)
int sumRegion(int row1, int col1, int row2, int col2) {
    //Return the answer as given below
    return v[row2+1][col2+1]-v[row2+1][col1]-v[row1][col2+1]+v[row1][col1];
}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */