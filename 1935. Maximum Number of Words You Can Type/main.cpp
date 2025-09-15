class Solution {
public:
    bool check(string s, vector<int>&freq) {
        for(auto &ch : s) {
            int c = ch-'a';
            if(freq[c] != 0) {
                return false;
            }
        }
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int>freq(26,0);
        for(auto &ch : brokenLetters ) {
            int a = ch-'a';
            freq[a]++;
        }  
        string word;                         
        // Create a stringstream object initialized with the sentence
        // This lets us read word by word like a stream
        stringstream ss(text);            
        int count = 0;
        // Extract words from the stringstream one by one until no more words left
        while (ss >> word) {
            cout << word << endl;
            if(check(word,freq)) {
                count++;
            }          
        }
        return count;
    }
};
