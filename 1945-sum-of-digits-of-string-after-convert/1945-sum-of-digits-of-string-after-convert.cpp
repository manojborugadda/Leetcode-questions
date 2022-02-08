class Solution {
public:
    int getLucky(string s, int k) 
    {
        string str = "";
        int result=0;
        for(auto &c : s) {
            str += to_string((c-'a') + 1);     // similar to //////////int(s[c]) - 96////////
        }
        
        while(k--){
            
            int sum = 0;
            for(char c : str)
            {
                sum += c - '0';    // adding the digits in the string str/////////
            }
            
            str = to_string(sum);
            result = sum;
        }
        
        return result;
    }
};