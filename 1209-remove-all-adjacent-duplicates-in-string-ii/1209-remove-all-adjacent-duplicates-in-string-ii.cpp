// in this problem we used VECTOR'S functions like BACK(),POP_BACK(),PUSH_BACK()
// STRING(VALUE,CHAR) ---- forms the string of "Char" with "Frequency" 

class Solution {  // TC:O(N) SC:O(N)
public:
    string removeDuplicates(string s, int k) {
        
        string ans = "";              // storing the answer string
        vector<pair<char,int>>count; // pair which takes the "char" and its "frequency"
        
        for(int i = 0;i<s.length();i++) {   
            // if vector is empty OR top element of the vector IS NOT Equal to present element then PUSH into the vector
            if(count.size() == 0 or s[i] != count.back().first) {
                count.push_back({s[i],1});
            }else {
                count.back().second++;
            }
            
            // if the top element freqency is EQUAL to the K we POP that element from the vector        
            if(count.back().second == k) { 
                count.pop_back();
            }
        }
        
        int n = count.size();
        // forming the string from the elements present in the vector
        for(int i = 0;i<count.size();i++) {
            ans  = ans+string(count[i].second,count[i].first);
        }
        return ans;
    }
};