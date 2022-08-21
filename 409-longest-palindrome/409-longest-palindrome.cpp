class Solution {
public: //TC:O(N)  SC:O(1)
    int longestPalindrome(string s) {
        vector<int>hash(256);
        for(auto x : s){  //Taking the freq map
            hash[x]++;
        }
        
        int count = 0 , odd = 0;
        for(auto x:hash) {
            count += 2*(x/2); //summation of 2*(freq/2)
            if(x%2 == 1){ // if ODD freq is present we ADD 1
                odd = 1;
            }
        }
        return count+odd;
    }
};


/*
1) condition: AABBCC => A-2,B-2,C-2 ==> sum of EVEN frequencies
2)condition : AABBBCC => A-2,B-3,C-2 ==> sum of EVEN freq + 1 ODD freq
3)condition : AAABBCCC => A-3,B-2,C-3 ==>this case is different and have multiple ODD freq 

ALGO: summation of 2*(freq\2) + 1(if any ODD freq is present)

for 3rd case:
A-3 => 2*(3/2)  = 2*(1) = 2
B-2 => 2*(2/2) = 2*1 = 2
C-3 => 2*(3/2)  = 2*(1) = 2
TOTAL = 2+2+2 + 1(if any odd freq is there) 
*/