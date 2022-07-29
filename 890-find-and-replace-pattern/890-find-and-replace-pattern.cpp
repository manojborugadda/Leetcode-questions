class Solution { //TC:O(N*K)  SC:O(N*K)   // N--> no.of words K---> length of the words
public:
    bool isMatches(string word,string pattern){
        vector<char>PatternToWord(26,0);
        vector<char>WordToPattern(26,0);
        
        for(int i = 0;i<word.size();i++){
            
            char wordChar = word[i];
            char patternChar = pattern[i];
            
            if(PatternToWord[patternChar-'a'] == 0){
                PatternToWord[patternChar-'a'] = wordChar;
            }
            
            if(WordToPattern[wordChar - 'a'] == 0){
                WordToPattern[wordChar - 'a'] = patternChar;
            }
            
            if(PatternToWord[patternChar-'a'] != wordChar or 
                 WordToPattern[wordChar - 'a'] != patternChar ){
                return false;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;//answer vector
        for( auto &w : words)
        {
          if(isMatches(w , pattern))//if successfuly matches we add that word into the Answer vector
          {
              ans.push_back(w);   
          }
        }
        
        return ans;
    }
};