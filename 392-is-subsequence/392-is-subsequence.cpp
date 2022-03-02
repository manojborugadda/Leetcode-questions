class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0) return true;
        int j = 0;// for traversing the S string 
        for(int i = 0;i<t.length();i++){
            if(t[i]==s[j]) j++;
            if(j==s.length()) return true; //finally we checked characters in the string S and we return TRUE
        }
        return false;
    }
};