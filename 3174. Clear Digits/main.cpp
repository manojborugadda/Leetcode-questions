class Solution {//TC:O(N)  SC;O(N)
public:
    string clearDigits(string s) {
        string ans = "";
        for(char ch : s) {
            if(isdigit(ch)) {
                if(!ans.empty()) {
                    ans.pop_back();
                }
            }else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
