class Solution {
public:
    string addStrings(string str1, string str2) 
    {
         //Before proceeding further, make sure length of str2 is larger
        if(str1.length() > str2.length())

           {
            swap(str1,str2);
           }
        // taking empty string for storing the result -------
        string str;
        int carry=0;
        int n1 = str1.length();
        int n2 = str2.length();
        // reverse the strings-----
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        //////now addition-------
        for(int i=0;i< n1;i++)
        {
            int sum = ( (str1[i]-'0') + (str2[i]-'0') + carry );
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
        //and now we add the remaining digits of the larger string
        for(int i=n1;i< n2;i++)
        {
            int sum = ( (str2[i]-'0') +  carry );
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if(carry) ///////adding the remaining carry--------
            str.push_back(carry+'0');

        //reverse the resulting string
        reverse(str.begin(),str.end());
        //cout<<str<<endl;
        
    return str;
    }
};