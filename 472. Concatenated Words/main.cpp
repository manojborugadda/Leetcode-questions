class Solution {
public:
    set<string>set;
    vector<string>ans;
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto x : words) {
            set.insert(x);
        }

        for(string x : words) {
            if(dfs(x)) {
                ans.push_back(x);
            }
        }
        return ans;
    }

    bool dfs(string word) {
        for(int i = 1;i<word.length();i++) {
            string prefix = word.substr(0,i);
            string suffix = word.substr(i);
            if( (set.find(prefix)!=set.end() and set.find(suffix)!=set.end() )
                or ( set.find(prefix)!=set.end() and dfs(suffix)  ) ) {
                return true;
            }
        }
        return false;
    }
};
