class Solution {
public:
        // adding binary digits
    /*  1 + 1 = 10
        0 + 1 = 1
        1 + 0  = 1
    */
    string addBinary(string a, string b){
        string ans;
        int carry = 0;
        int n1 = a.size()-1,n2 = b.size()-1;
        while(n1 >=0 or n2 >=0  or carry){
            
            if(n1>=0){
                carry += a[n1]-'0';
                n1--;
            }
            
            if(n2>=0){
                carry += b[n2] - '0';
                n2--;
            }
            
        ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};