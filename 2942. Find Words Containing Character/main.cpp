class Solution {//TC:O(N)  SC:O(1)
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int n = words.size();
        for(int i = 0;i<n;i++) {
            if(words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
