class Solution {
public:
    int myAtoi(string s) {
     stringstream m(s);
        int x=0;
        m>>x;
        return x;
    }
};