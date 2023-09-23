class Solution { //Use hashmap for storing string and length of word chain
public:
    // TC:O(M*N*K) M-->for 1st loop  , N--> for 2nd or inner loop  , K--> for string concetanation
    //SC:O(N) used extra space HASHMAP
    
    // comparator function
    static bool compare(string s1,string s2){
        return s1.size() < s2.size(); // if s1 size less than s2 it return TRUE else FALSE
    }
    
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string,int>dp; //it stores predecessor word and chain size
        
//sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1.length()<s2.length();});
        sort(words.begin(),words.end(),compare);
        int len = 1;// length of the longest possible word chain variable
        for(auto word : words){
            dp[word] = 1;
            for(int i = 0;i<word.length();i++){
    //removing ith alphabet from the string and check remaining string is available in the DP 
                string predecessor = word.substr(0,i)+word.substr(i+1);
                if(dp.find(predecessor)!=dp.end()){
                    dp[word] = max(dp[word] , 1+dp[predecessor]);
                    len = max(len,dp[word]);
                }
            }
        }
        return len;
    }
};
