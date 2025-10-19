class Solution {//TC;O( K * N)
//k = number of unique reachable states (bounded by permutations of digits).
public:
    string addAtoOddIndices(string str, int a) {
        for(int i =0;i<str.length();i++) {
            if(i % 2 != 0) {
                //Use modulo 10 to wrap around after 9.
                int digit = ( str[i] - '0' + a ) % 10;
                str[i] = '0' + digit;
            }
        }
        return str;
    }
    string rotateRight(string str, int b) {
        //Take last b characters and move them to the front.
        int n = str.length();
        b = b % n;
        string last = str.substr(n - b);
        string first = str.substr(0, n - b);
        return last+first;
    }
    string findLexSmallestString(string s, int a, int b) {
        queue<string>q;
        set<string>st;
        string smallest = s;
        q.push(s);
        st.insert(s);
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if(curr < smallest) {
                smallest = curr;
            }

            //operation 1 -- adding 'a' to  ODD indices
            string s1 = addAtoOddIndices(curr, a);
            if(st.find(s1) == st.end()) {
                st.insert(s1);
                q.push(s1);
            }

            //operation 2 -- rotate 's' Right by 'b' positions
            string s2 = rotateRight(curr, b);
            if(st.find(s2) == st.end()) {
                st.insert(s2);
                q.push(s2);
            }
        }
        return smallest;
    }
};
//Each operation (add/rotate) is O(n) to build a new string.
