class Solution {
public:
       bool palindrome(string s)
    {
        int e = s.size()-1;
        for(int i = 0; i < s.size() ; i++)
        {
            if(s[i]!= s[e--]) 
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) 
    {
        for(auto s : words)
        {
            if(palindrome(s)) return s;
        }
        return "";
    }
    
};