class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n,0));
        
        int left = 0 , right = n-1 , top = 0 , bottom = n-1;
        int direction = 1;
        int k = 1;
        
        while(left<=right and top<=bottom){
            
               if(direction==1){  // filling from left to right of the matrix where "row" is fixed
                   for(int i = left;i<=right;i++){
                       ans[top][i] = k++;
                   }
                   
                   direction = 2;
                   top++;
               }
            
           else if(direction==2){ // filling from top to bottom in the matrix where column is fixed
                for(int i = top;i<=bottom;i++){
                    ans[i][right] = k++;
                }
                direction = 3;
                right--;
            }
            
           else if(direction ==3){ // filling from right to left in the matrix where row is fixed
                for(int i = right ;i>=left;i--){
                    ans[bottom][i] = k++;
                }
                
                direction = 4;
                bottom--;
            }
            
           else if(direction == 4){ // filling from bottom to top in the matrix
                for(int i = bottom;i>=top;i--){
                    ans[i][left]= k++;
                }
                direction = 1;
                left++;
            }
        }
        return ans;
    }
};