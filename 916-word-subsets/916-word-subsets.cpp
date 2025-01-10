class Solution {//SC:O(m+N)
public:
    bool isUniversal(string s1, unordered_map<char, int>& map) {
        unordered_map<char, int> map1;
        for (auto s : s1) {
            map1[s]++;
        }
        for (auto [a, b] : map) {
            if (map1[a] < b) {
                return false;
            }
            if (map1.find(a) == map1.end()) {
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> map;
        for (auto word : words2) {//(m*n)
            unordered_map<char, int> tempMap;
            for (char ch : word) {
                tempMap[ch]++;
            }
            for (auto [ch, freq] : tempMap) {
                map[ch] = max(map[ch], freq);
            }
        }
        vector<string> ans;
        for (auto word : words1) {//(L*M) -- L is the size  of the word1 vector
            if (isUniversal(word, map)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
