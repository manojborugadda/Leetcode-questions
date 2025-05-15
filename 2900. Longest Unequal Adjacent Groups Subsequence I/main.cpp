class Solution {//TC:O(N)  sc:O(1)
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        if(n == 1) return {words[0]};
        vector<string>idx;
        int i = 0 ;
        while(i < n-1) {
            if(groups[i] != groups[i+1]) {
                idx.push_back(words[i]);
            }i++;
        }
        idx.push_back(words[n-1]);
        return idx;
    }
};
