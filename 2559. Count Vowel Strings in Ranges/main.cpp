class Solution {//TC:O(N+M) where 'N' is the Prefix sum vector and 'M' is the queries lenght --------------  SC:O(N+M)
public:
    bool isVowel(char ch) {
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n,0);
        vector<int>ans;
        //constructing the preFix sum for the first index
        if(isVowel(words[0].front()) and isVowel(words[0].back())) prefix[0] = 1;
        else prefix[0] = 0;

        // continuing the prefix sum calculation
        for(int i =1;i<n;i++) {  
            if(isVowel(words[i].front()) and isVowel(words[i].back())) {
                prefix[i] = prefix[i-1] + 1;
            }else {
                prefix[i] = prefix[i-1] + 0;
            }   
        }

        // in the ( i ,j) in the queries, if 'i' is not equal to ZERO we can push the prefix[j] value to the ans;
        for(auto &query : queries) {
            int a = query[0];
            int b = query[1];
            if(a > 0) {
                ans.push_back(prefix[b] - prefix[a-1]);
            }else {
                ans.push_back(prefix[b]);
            }
        }
        return ans;
    }
};
