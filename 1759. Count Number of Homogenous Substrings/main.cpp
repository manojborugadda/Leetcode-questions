class Solution {//TC:O(N)  SC:O(1)
public:
    int countHomogenous(string s) {
        long long MOD = 1e9+7;
        long long i = 0 , j = 0;
        long long ans = 0;
        while(j < s.length()) {
            if(s[i] == s[j]) {
                j++;
            }else {
                ans += ( (j-i)*(j-i+1)/2 )%MOD;
                i = j;
                j++;
            }
        }
        ans += ( (j-i)*(j-i+1)/2 )%MOD;
        return ans%MOD;
    }
};
/*
One and only thing you need to know to make this problem Easy is that homogenous string "aaaaaaa" of length N contains N * (N + 1) / 2 homogenous substrings (sum of the arithmetic progression).

Then  just sum them up not forgetting about modulo.
*/
