class Solution {  //TC:O(N)  SC:O(1)
public:
    int compress(vector<char>& chars) {
        int n = chars.size(); 
        if(n == 1 or n == 0 ) return n;
        string s1 = "";
        char prev = chars[0];
        int count = 1;
        for(int i = 1;i<n;i++) {
            if(chars[i] == prev) {
                count++;
            }else {
            if(count > 1) {
                s1 += prev+to_string(count);
            }else s1 += prev;
            
            count = 1;
            prev = chars[i];
          }   
        }
        //if any remaining count is there 
            if(count > 1) {
                s1 += prev+to_string(count);
            } else s1 += prev;
        
        chars.clear(); //clearing the input Array
        for(int i = 0;i<s1.length();i++) {
            chars.push_back(s1[i] ); //inserting the characters from s1 to the input vector
        }
            return chars.size();
    }
};
