class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n >=2) {
            int quotient = n/2;
            ans += quotient;
            n = n-quotient;
        }
        return ans;
    }
};
