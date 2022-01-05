class Solution {
public:
    bool hashmap(string pattern,vector<string>&words){
        map<string,char>mp1; // mapping words to pattern
        map<char,string>mp2;  // mapping pattern to words

        for(int i=0;i<words.size();i++){
            if(mp1[words[i]]=='\0'){         /// check if word exists in map or not
                mp1[words[i]] = pattern[i];
            }
            if(mp2[pattern[i]]=="")         ///check if pattern exists in map or not
            {
                mp2[pattern[i]]=words[i];
            }
            if(mp1[words[i]]!=pattern[i] || mp2[pattern[i]]!=words[i])
                return false;
        }
        return true;
    }
    
    bool wordPattern(string pattern, string s) 
    {
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss >> word){
            words.push_back(word);
        }
        
        if(pattern.length()!=words.size()){
            return false;
        }
        
        return hashmap(pattern,words);
        
    }
};