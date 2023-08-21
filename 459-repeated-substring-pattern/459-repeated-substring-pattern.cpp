class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ans = s.substr(1)+s.substr(0,s.length()-1);
        return ans.find(s) != -1; // it checks  first index of the substring is there or NOT// if it is not there means we return false;
    }
};


////////////////////

class Solution {//TC : 2*sqrt(n)*O(2n)
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = n/2;i>=1;i--) {
            if(n%i == 0) {
                int times = n/i;
                string pattern = s.substr(0,i);
                string newSubstring = "";
                while(times--) {
                    newSubstring += pattern;
                }

                if(newSubstring == s) {
                    return true;
                }
            }
        }
        return false;
    }
};
