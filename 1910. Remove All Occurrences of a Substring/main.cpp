// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         int len = part.length();
//         while(s.find(part) != string::npos) {
//             int idx = s.find(part);
//             s = s.substr(0,idx) + s.substr(idx+len , s.length());
//         }
//         return s;
//     }
// };

class Solution {//TC:O(N)  SC:O(1)
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        int m = s.length();
        string ans = "";
        for(int i =0 ;i<s.length();i++) {
            ans.push_back(s[i]);
            if( s[i] == part[n-1] and ans.size() >= part.size() ) {
                if(ans.substr(ans.length()-n) ==  part) {
                    ans.erase(ans.length()-n);
                }
            }
        }
        return ans;
    }
};
