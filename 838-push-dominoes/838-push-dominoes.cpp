class Solution {  //TC:O(N)  SC:O(N)
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<char>ans(n);
        vector<int>left(n,0), right(n,0);
        int nearestLeftIndex = -1 , nearestRightIndex = -1;
        
        //left vector having the NearestLeftIndices
        for(int i = n-1;i>=0;i--) {
            if(dominoes[i] == 'L') {
                nearestLeftIndex = i;
            }else if(dominoes[i] == 'R') {
                nearestLeftIndex = -1;
            }
            left[i] = nearestLeftIndex;
        }
        
        //right vector having the NearestRightIndices
        for(int i  = 0;i<n;i++) {
            if(dominoes[i] == 'L') {
                nearestRightIndex = -1;
            }else if(dominoes[i] == 'R') {
                nearestRightIndex = i;
            }
            right[i] = nearestRightIndex;
        }
        
        //checking for the nearest index for each character in the Dominoes
        for(int i = 0;i<n;i++) {
            if(dominoes[i] == '.') {
            int nearestLeft = left[i];
            int nearestRight = right[i];
            
            int leftDiff = nearestLeft == -1 ? INT_MAX : abs(nearestLeft - i);
            int rightDiff = nearestRight == -1 ? INT_MAX : abs(nearestRight - i);
            
            if(leftDiff == rightDiff) {
                ans[i] = '.';
            }else if(leftDiff < rightDiff) {
                ans[i] = 'L';
            }else if(leftDiff > rightDiff) {
                ans[i] = 'R';
            }
                
            } else{
                ans[i] = dominoes[i];
            }
    }
        //vector of characters into string
        string s(ans.begin(), ans.end());
        return s;
    }
};