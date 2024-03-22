class Solution {//TC:O(N) SC:O(LENGTH OF the S)
public:
    bool isPrefixString(string s, vector<string>& words) {
        string str = "";
        for(auto x : words) {
            str += x;
            if(str == s) {
                return true;
            }
        }
        return false;
    }
};
