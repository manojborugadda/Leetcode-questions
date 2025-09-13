class Solution {
public:
    bool isVowel(char s) {
        return ( s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u');
    }
    int maxFreqSum(string s) {
        unordered_map<char,int>vowel,consonant ;
        for(auto ch : s) {
            if(isVowel(tolower(ch))) {
                vowel[ch]++;
            }else {
                consonant[ch]++;
            }
        }
        int maxV = 0;
        int maxC = 0;
        for(auto [a,b] : vowel) {
            maxV = max(maxV,b);
        }

        for(auto [a,b] : consonant) {
            maxC = max(maxC,b);
        }

        return maxV  + maxC;

    }
};
