class Solution {
public:
    string makeFancyString(string s) {
        if(s.length() < 3 ) return s;
        char c = s[0];
        string ans = "";
        ans+= c;
        int freq  = 0;
        for(int i =1 ;i<s.length();i++) {
            if(s[i] == c) {
                freq++;
            }else {
                freq = 0;
            }
            if(freq < 2) {//no three consecutive characters are equal.
                ans += s[i];
            }
            c = s[i];
        }
        return ans;
    }
};
