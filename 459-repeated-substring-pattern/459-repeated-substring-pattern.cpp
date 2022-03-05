class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ans = s.substr(1)+s.substr(0,s.length()-1);
        return ans.find(s) != -1; // it checks  first index of the substring is there or NOT// if it is not there means we return false;
    }
};