class Solution { //Time Complexity : O(4 ^ N)
                // Space Complexity : O(N)
public:
    
    bool backtrck(int i ,vector<int>& matchsticks,int s1, int s2 , int s3 , int s4 ){
        //Base Case
        if(i==matchsticks.size()){
            if(s1==0 and s2 == 0 and s3 == 0 and s4 == 0){
                return true;
            }else{
                return false;
            }
        }
        
        // if matchstick size is less than side(a or b or c or d)  size , then in that case we will not explore that because that will cause negative side which is not possible
        
  		//Now we will explore for all side for given index

        if(matchsticks[i] <= s1){
            s1 -= matchsticks[i];
            if( backtrck(i+1,matchsticks,s1,s2,s3,s4) ){
                return true;
            }
            s1 += matchsticks[i]; // backtrack step
        }
        
         if(matchsticks[i] <= s2){
            s2 -= matchsticks[i];
            if( backtrck(i+1,matchsticks,s1,s2,s3,s4) ){
                return true;
            }
            s2 += matchsticks[i]; // backtrack step
        }
        
         if(matchsticks[i] <= s3){
            s3 -= matchsticks[i];
            if( backtrck(i+1,matchsticks,s1,s2,s3,s4) ){
                return true;
            }
            s3 += matchsticks[i]; // backtrack step
        }
        
         if(matchsticks[i] <= s4){
            s4 -= matchsticks[i];
            if( backtrck(i+1,matchsticks,s1,s2,s3,s4) ){
                return true;
            }
            s4 += matchsticks[i]; // backtrack step
        }
        return false;//If none of the explored option return TRUE then  we have to return FALSE  
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();  // size of the matchsticks---------
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        
        //// if sum of all number of array is not divisible by 4 , then we can not create a square
        ////  if less than four number present in array , then we can not make square
        if(sum%4 != 0  or n < 4){
            return false;
        }
        
        int len = sum/4;
        
        // for not getting TLE we sort in decreasing order
        // here we sort our array in reverse order to escape more cases i.e DECREASING ORDER
        sort(matchsticks.rbegin(),matchsticks.rend());
        
        return backtrck(0,matchsticks,len,len,len,len);
        
    }
};