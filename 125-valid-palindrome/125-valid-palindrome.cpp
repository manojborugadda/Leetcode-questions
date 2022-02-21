class Solution {
public:
    bool isPalindrome(string s) 
    { int l=0,r=s.length()-1;
        while(l<r){
            if (!isalnum(s[l]) || s[l] == ' ')
                l++;
            else if(!isalnum(s[r]) || s[r] == ' ')
                r--;
            else{
                if(tolower(s[l])!=tolower(s[r])){
                    return false;
                  }
                l++;
                r--;
            }//end else   
        }//end while
        return true;
    }
};
