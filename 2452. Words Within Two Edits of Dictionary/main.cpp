class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for (int i = 0; i < queries.size(); i++) {
        for (auto &word : dictionary) {
            int diff = 0;
            for (int j = 0; j < queries[i].length(); j++) {
                if (queries[i][j] != word[j]) {
                    diff++;
                }
                if (diff > 2) break;
            }
            if (diff <= 2) {
                ans.push_back(queries[i]);
                break; // Only add once
            }
        }
    }
        return ans;
    }
};
