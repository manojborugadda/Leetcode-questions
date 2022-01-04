class Solution {
public:    
    bool isPalindrome(int x) 
    {
      string s = to_string(x) ;
      int right = s.length()-1;
       int left = 0;
    if(s.length()==0){
      return true;
    }
        while(left<right+1)
        {
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};