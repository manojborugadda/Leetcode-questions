class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (int i = 0; i < num.length(); i++) {
            // remove digits from back of res which are greater than our current char 
            while(!res.empty() && res.back() > num[i] && k > 0) {
                res.pop_back();
			    k--;
            }
            
            // do not push leading zeros  
            if(!res.empty() || num.at(i) != '0')
                res.push_back(num[i]);
          }
        
        // make sure k characters are deleted
        while(!res.empty() && k) {
            res.pop_back(); 
            k--;
        }
        
        return res.empty() ? "0" : res;
    }
};