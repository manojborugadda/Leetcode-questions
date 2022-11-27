class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length() , m = t.size();
        int i = 0 , j = 0;
        while(i<n and j < m) {
            if(s[i] == t[j]) {
                i += 1 ;
                j += 1; 
            } else {
                i = i+1;
            }
        }
        return m-j;
    }
};