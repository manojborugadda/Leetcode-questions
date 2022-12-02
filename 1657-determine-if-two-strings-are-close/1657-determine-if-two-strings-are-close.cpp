class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length() , n  = word2.length();
        if(m != n) return false;
        
        set<int>s1,s2;
        vector<int>freq1(26,0) , freq2(26,0);
        
        for(char ch : word1) {
            freq1[ch - 'a']++;
            s1.insert(ch);
        }
        
        for(char ch : word2) {
            freq2[ch - 'a']++;
            s2.insert(ch);
        }
        
        //sorting the freq vectors for checking if the same is there or not
        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));
        //if the characters in both the sets is euqal and  freq vectors are equal we return TRUE
        return s1 == s2 and freq1 == freq2;
        
        
    }
};