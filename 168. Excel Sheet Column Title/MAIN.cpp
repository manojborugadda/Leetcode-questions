class Solution {//TC:O(N) SC:O(1)
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans= "";
        while(n ) {
            n--;
            ans += char('A'+n%26);
            n = n/26; 
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
