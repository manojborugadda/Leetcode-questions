class Solution { //TC:O(N^2) where N is the string length SC:O(M)
public:
     unordered_map<string,bool>dp;
    bool solve(string s,unordered_set<string>&m){
        if(s.length()==0){
            return true;
        }
        if(dp.find(s)!=dp.end()) return dp[s];
        for(int i=0;i<s.length();i++){
            string r=s.substr(0,i+1);
            if(m.count(r)){
                if(solve(s.substr(i+1),m)) {
                    return dp[s]=true;
                }
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string>m;
        for(auto x:wordDict){
            m.insert(x);
        }
         return solve(s,m);
    }
};

/*
The code uses a recursive approach with memoization to determine if the input string s can be broken down into valid words from the given wordDict. 
It iterates through all possible prefixes of the input string, and for each prefix, it checks if it exists in the wordDict.
If found, it makes a recursive call with the remaining suffix of the input string. Memoization is used to avoid redundant computations and improve efficiency. 
If a valid segmentation is found, the function returns true, otherwise false.
*/
