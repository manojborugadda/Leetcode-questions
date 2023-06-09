class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch=letters[0];
        for(int i=0;i<letters.size();i++)
        {
            if(letters[i]>target)
            {
                ch=letters[i];
                break;
            }
        }
        return ch;   
    }
};
