class Solution {  //TC:O(N*2^N) SC:O(N)
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        backtrack(ans,temp,s);
        return ans;
    }

    void backtrack(vector<vector<string>>&ans,vector<string>&temp,string s) {
        if(s.length() == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i<s.size();i++) {
            string s2 = s.substr(0,i+1);
            if(isPalindrome(s2)) {
                temp.push_back(s2);
                backtrack(ans,temp,s.substr(i+1));
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string str) {  //TC:O(N)  SC:O(1)
      for(int i = 0;i<str.length()/2;i++) {
          if(str[i] != str[str.size()-i-1]) {
              return false;
          }
      }
       return true;
    }
};
