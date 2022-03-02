class Solution {
public:
    string multiply(string A, string B) {
        int n = A.length(),m = B.length();
        string res(n+m,'0');

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int num = (A[i] - '0') * (B[j] - '0') + res[i+j+1] - '0';
                res[i+j+1] = num%10 + '0';
                res[i+j] += num/10; // addding the CARRY to the previous cell in the string
            }
        }
        // cout<<res;
        for(int i=0;i<res.length();i++) if(res[i] != '0') return res.substr(i);
        return "0";
    }
};