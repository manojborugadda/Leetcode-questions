class Solution {//TC:O(N)  SC:O(1)
public:
    int minimumLength(string s) {
        int n = s.length();
        int l = 0 , r = n-1;
        while(l < r) {
            if(s[l]!=s[r]) {
                break;
            }
            char ch = s[l];
            while(l <= r and s[l] == ch ) {
                l++;
            }
            while(l <= r and s[r] == ch) {
                r--;
            }
        }
        return r - l + 1;
    }
};
