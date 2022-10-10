class Solution {  //TC:O(N) SC:O(1)
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() <= 1) return "";
        int n = palindrome.length();
        for(int i = 0;i<n/2;i++){
            if(palindrome[i]!= 'a') {
                palindrome[i] = 'a';
                return palindrome;
         }
    }
        ///if we dont encounter any non character which is not equal to 'a' it means all characters are 'a' AND WE CHANGE the last character in the string given
            palindrome[n-1] = 'b';
            return palindrome;
    }
};