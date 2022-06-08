class Solution {  // T(n) = 2T(n log n) + O(n) ≈ O(n log n)  //SC:O(N)
public:
    
    // we use DIVIDE AND CONQUER Algorithm here 
    
    int longestSubstring(string s, int k) {
        
        int n = s.size(); // length of the string
        // base cases
        if(n==0 or n<k) return 0;
        
        unordered_map<char,int>map;
        int sub1 , sub2;
        
        for(auto ch:s) map[ch]++;
        
        for(int i = 0;i<s.size();i++){
            if(map[s[i]] < k){
            sub1 = longestSubstring(s.substr(0,i),k);//sub-string from 0 to i Index
            sub2  = longestSubstring(s.substr(i+1),k); //sub-string from i+1 to Last Index
                break;
            }
            if(i ==  n-1){
                return n;
            }
        }
        
        return max(sub1,sub2);
    }
};