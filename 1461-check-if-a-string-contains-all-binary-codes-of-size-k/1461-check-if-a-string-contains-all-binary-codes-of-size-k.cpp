class Solution {  // TC: O( (n-1)*k ) SC:O(2^k)
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.size();
        if(n < k) return false; // corner case
        
        set<string>hashset; // to get the distinct substrings and for TC , we use SET
        // inserting all the substrings of input string which are binary code of length K
        for(int i = 0;i<n-k+1;i++){ 
            hashset.insert(s.substr(i,k));
        }
        
        // if the size of the HASH_SET is equal to Binary codes of length K we return TRUE
        if(hashset.size() == pow(2,k) ){  
            return true;
        }
        else{
            return false;
        }
        
    }
};