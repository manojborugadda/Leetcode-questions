class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int m = rolls.size();
        int mTotal = 0;
        
        // calculating the mTotal
        for(int i = 0;i<m;i++){
            mTotal = mTotal+rolls[i];
        }
        
        // for calculating nTtotal
         int nTotal = (mean*(m+n) - mTotal);
         
        // boundary condition 
        if(nTotal < n || nTotal > n*6){
            return {};
        }
        
        // for carrying the result in vector 'res'
         vector<int>res;
         
         while(nTotal){
             int dice = min(nTotal - n +1,6); // we are taking the minimum value here for keeping in array of length 'n' containing the missing observations.
             res.push_back(dice);
             nTotal = nTotal - dice;
             n = n-1;
         }
    return res;  
    }
};