class Solution {
public:
    int minimumSum(int num) 
    {
        string str = to_string(num);
        sort(str.begin(),str.end());
        int n = ( (str[0]-'0')*10 + str[2]-'0' ) + ( (str[1]-'0')*10 + str[3]-'0' );
         return n;
        // our aim is to keep minimum element in the 10's place in the num1 and num2 so that the sum of the these digits will be minimum
        // for example  The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
        // 29 = 2*10+9
        //23 = 2*10+3
    }
};