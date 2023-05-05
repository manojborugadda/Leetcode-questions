class Solution {//TC:O(N)  SC:O(1)
public:

        bool isVowel(char ch) {
            if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
                return true;
            }
            return false;
        }
    int maxVowels(string s, int k) {
        int maxNoVowels = 0,count = 0;
        //first we calculate the no.of vowels in the  first substring of length K
        for(int i = 0;i<k;i++) {
            if(isVowel(s[i])) {
                count++;
            }
            maxNoVowels = max(count,maxNoVowels);
        }

        int leftIndex = 0;//index which is useful for deleting from left side of String
        for(int i = k;i<s.size();i++) {
            if(isVowel(s[leftIndex])) count--;//we decrement the count if the DELETING char is VOWEL
            if(isVowel(s[i])) count++;//when the slide is updating and if the current char is VOWEL
            leftIndex++;
            maxNoVowels = max(count,maxNoVowels);
        }
        return maxNoVowels;
    }
};
