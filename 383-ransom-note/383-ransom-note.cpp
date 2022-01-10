class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char,int> m;
        for (int i = 0; i < magazine.length() ; i++){
            m[magazine[i]] += 1;
        }
        for (int j = 0; j < ransomNote.length() ; j++){
            if (m[ransomNote[j]] == 0) {
                return false;
            }
            m[ransomNote[j]] -= 1;
        }
        return true;
    }  
};