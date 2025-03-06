class Solution {
public:
    typedef long long int ll;
    long long coloredCells(int n) {
        ll ans = 1 + 2LL * (n - 1) * n;
        return ans;
    }
};

/*
for n = 1, ans = 1
for n = 2, ans = 1 + 4
for n = 3, ans = 1 + 4 + 8
for n = 4, ans = 1 + 4 + 8 + 12
so n = 4 ans = 1 + 4 ( 1 + 2 + 3)
               1 + 4(3*(3-1)/2)
               1 + 4(3)
               = 13
 this is the generic formula for this  -------->  ans=1+2⋅(n−1)⋅n


*/
