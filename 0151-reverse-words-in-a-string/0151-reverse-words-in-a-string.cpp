class Solution { //using stringstream 
public://TC:O(N)  SC:O(1)
    string reverseWords(string s) {
        stringstream ss(s);
        string ans,word;
        while(ss>>word) {
            ans =  word+" "+ans;
        }
        ans.pop_back();
        return ans;
    }
};