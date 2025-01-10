class Solution {
public:
    bool isPrefix(string s1,string s2) {
        int len = s2.length();
        if(len > s1.length()) return false;
        if(s1.substr(0,len) == s2) {
            return true;
        }
        return false;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto str : words) {
            if(isPrefix(str,pref)) {
                count++;
            }
        }
        return count;
    }
};
