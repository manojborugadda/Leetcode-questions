class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>map;
        int ans = 0 , unpaired = 0;
        for(string word : words) {
            if(word[0] == word[1]) { //if the word itself is palindrome
                if(map[word] > 0) {
                    map[word]--;
                    unpaired --;
                    ans += 4;
                }else {
                    map[word]++;
                    unpaired++;
                }
            } else { //if the word itself is not a palindrome
                string reverse_word = word;
                ///reversing the word
                reverse(begin(reverse_word),end(reverse_word));
                if(map[reverse_word] > 0) {
                    map[reverse_word]--;
                    ans += 4;
                }else {
                    map[word]++;
                }
            }
        }
        
        if(unpaired > 0) ans += 2;
        return ans;
    }
};