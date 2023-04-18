class Solution {//TC:O(N) 
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0,j = 0;
        string ans = "";
        int m = word1.length() , n = word2.size();
        while(i<m and j<n) {
            ans = ans+word1[i++]+word2[j++];
        }
        while(i<m) {
            ans = ans+word1[i++];
        }
        while(j<n) {
            ans = ans+word2[j++];
        }

        return ans;
    }
};
