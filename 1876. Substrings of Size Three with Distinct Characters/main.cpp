class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int i = 0, j = i+1, k = j+1;
        if(s.length() < 3) {
            return 0;
        }
        int count = 0;
        while(i < n-2 and j < n-1 and k < n) {
            if(s[i] != s[j] and s[j] != s[k] and s[i] != s[k]) {
                count++;
                i++;j++;k++;
            }else {
                i++;j++;k++;
            }
        }
        return count;
    }
};
