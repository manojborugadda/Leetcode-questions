class Solution {
public:
    bool rotateString(string s, string goal) {
     
        if(s.size()>goal.size())return false;
    string data=s+s;
    return(data.find(goal)!=string::npos);
    }
};