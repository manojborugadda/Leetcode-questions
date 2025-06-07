class Solution {//MIN HEAP with CUSTOM COMPARATOR
public: //TC: O(nlogn)  SC:O(N)
    typedef pair<char, int> pi;
    struct CustomComp  {
        bool operator()(const pi a, const pi b) {
            if( a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pi, vector<pi>, CustomComp > pq;
        int n = s.length();
        
        // Traverse the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    auto val = pq.top();
                    pq.pop();
                    s[val.second] = '*'; // Replace character with '*'
                }
            } else {
                pq.push({s[i], i}); // Push character and index
            }
        }
        string ans = "";
        for (char ch : s) {
            if (ch != '*') ans += ch;
        }
        
        return ans;
    }
};
