class Solution {
public:
    // bool isPowerOfThree(long long n)
    // {   
    //  if (n <= 0)
    //     return false;
    // if (n % 3 == 0)
    //     return isPowerOfThree(n / 3);
    // if (n == 1)
    //     return true;
    // return false;
    // }
    
    bool isPowerOfThree(int n) {
if(n<1)
return false;
if(n%3!=0 && n!=1)
return false;
if(n==1)
return true;
return isPowerOfThree(n/3);
    }
};