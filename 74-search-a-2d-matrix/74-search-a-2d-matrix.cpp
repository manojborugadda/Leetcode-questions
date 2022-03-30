class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      //  if(std::find(vector.begin(), vector.end(), item)!=vector.end()){
      for(int i = 0;i<matrix.size();i++){
          if(std::find(matrix[i].begin(),matrix[i].end(),target)!= matrix[i].end()){
              return true;
          }
      }
        return false;
}
    
};