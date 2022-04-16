class Solution {
public:
    
    vector<string>mp = {
                                "",
                                "",
                                "abc",
                                "def",
                                "ghi",
                                "jkl",
                                "mno",
                                "pqrs",
                                "tuv",
                                "wxyz"
                     };
    void generate(string digits,string temp,int start,vector<string>&ans){
        
        if( temp.length() == digits.size() ){
            ans.push_back(temp);
            return;
        }
        
        for(auto i: mp[digits[start]-'0']){
            temp.push_back(i);
            generate(digits,temp,start+1,ans);
            temp.pop_back(); // backtracking 
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string temp = "";
        generate(digits,temp,0,ans); // calling the generate function-
        return ans;
        
    }
};