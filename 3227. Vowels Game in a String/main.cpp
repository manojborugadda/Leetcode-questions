class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int vowCount = 0;
        for(auto ch : s) {
            if(isVowel(ch)) {
                vowCount++;
            }
        }
        if(vowCount == 0) {
            return false;
        }
        return true;
    }
};


