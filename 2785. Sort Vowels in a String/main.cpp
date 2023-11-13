class Solution {
public:
    string sortVowels(string s) {
        string vowels = "";
        for(char x : s) {
            if(x == 'a' or x == 'e' or x == 'i' or x == 'o' or x =='u' or x == 'A' or x == 'E' or x == 'I' or x == 'O' or x =='U') {
                vowels += x;
            }
        }
        sort(begin(vowels),end(vowels));
        int j = 0;
        for(int i = 0 ;i<s.length() ;i++) {
            char x = s[i];
            if(x == 'a' or x == 'e' or x == 'i' or x == 'o' or x =='u' or x == 'A' or x == 'E' or x == 'I' or x == 'O' or x =='U' ) {
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};
