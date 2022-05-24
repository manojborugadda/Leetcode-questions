/*
// Consider every INDEX as a CENTER, take TWO pointers, one on the LOW and one on the HIGH
    // keep checking and expanding these pointers, till the characters on left-right match
    // We need to check above scenarios for both even length and odd length strings, considering every index starting from 1, as the center
    // So for even length string, CENTER = i, LOW = i-1, HIGH = i (because we have two mid points for even length string)
    // For odd length string, CENTER = i, LOW = i-1 and HIGH = i+1. 
    */
class Solution {
public:
 string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxlen = 1;
     
        for (int i = 1; i<n; i++) {
            
            ////if the length of the string is EVEN
            int low = i-1;
            int high = i;
            while(low >= 0 and high < n) {
                if (s[low] == s[high]){
                    if (maxlen < high - low + 1) {
                        maxlen = high-low+1;
                        start = low;
                    }
                }
                else
                {
                  break;   
                }
                
                low--;
                high++;
            }
            
            ////if the length of the string is ODD
            low = i-1;
            high = i+1;
            while(low >= 0 and high < n) {
                if(s[low] == s[high]){
                    if (maxlen < high - low + 1) {
                        maxlen = high-low+1;
                        start = low;
                    }
                }
                else
                {
                 break;   
                }
                
                low--;
                high++;
            }
        }
    return s.substr(start, maxlen);//returning the longest palindrome substring in given string
    }
};