class Solution {
public:
    string reverseStr(string s, int k) 
    {
       for( int i=0;i<s.length();i=i+(2*k))
    {
        
        int l=i;
        
        int n= s.length()-1;
        
        int r = min(i+k-1,n);
           
        while(l<r)
        {
            
            swap(s[l],s[r]);
            l++;r--;
        }
        
        
    }
    
    return s;
    
}
    
};