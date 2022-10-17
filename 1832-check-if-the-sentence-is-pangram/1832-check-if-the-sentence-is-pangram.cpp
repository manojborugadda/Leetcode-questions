class Solution {
public:
    bool checkIfPangram(string sentence) {
        //if input lenght is less than 26 we cant proceed and return FALSE
        if(sentence.length() < 26) return false;
        vector<int>map(26,0);
        for(char x : sentence ) {
            map[x-'a']++;
        }
        
        for(int i = 0;i<26;i++) {
            if( map[i] == 0) {
                return false;
            }
        }
        return true;
    }
};