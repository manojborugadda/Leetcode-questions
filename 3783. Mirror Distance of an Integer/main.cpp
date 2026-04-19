class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x > 0) {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int ans = 0;
        ans = abs(n-reverse(n));
        return ans;
    }
};
