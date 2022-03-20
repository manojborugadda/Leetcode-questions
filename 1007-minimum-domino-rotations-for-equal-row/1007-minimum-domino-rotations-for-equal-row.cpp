class Solution {
public:
    int diff(vector<int>& tops, vector<int>& bottoms,int num){
        int top = 0,bottom = 0;
        for(int i = 0;i<tops.size();i++){
            if(tops[i]!=num and bottoms[i]!=num){
                return -1;  //if any value for num is not present at ith position of row and column than immediately return -1
            }
            if(tops[i]!=num){
                top++;
            }
            if(bottoms[i]!=num){
                bottom++;
            }
        }
         return min(top,bottom);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms){
        int swap1 = diff(tops,bottoms,tops[0]);
        int swap2 = diff(tops,bottoms,bottoms[0]);
         return( min(swap1,swap2) < 0 ) ? max(swap1,swap2) : min(swap1,swap2); //if swap is less than 0 then return max value to get positive value
    }
};