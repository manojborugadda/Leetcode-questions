class Solution {  //TC:O(N) SC:O(N)
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
         if(n==0) return 0;
        
        set<char>st;
        
        int right = 0 , left = 0;
        int maxlen = 0; // answer variable
        
        while(left < n)
        {
            if(st.count( s[left]) == 0 ){ // if we  cannot find the s[left] in string
                st.insert(s[left]);
                maxlen = max(maxlen,(int)st.size());
                left++;
            }
            else{ // if we find the s[left] in the string we ERASE the s[right]
                st.erase(s[right]);
                right++;
            }
        }
        
        return maxlen;
    }
};