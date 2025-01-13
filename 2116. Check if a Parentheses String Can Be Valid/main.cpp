class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) {
            return false;
        }
        stack<int> open_Brackets, can_change;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {  //compare with '0' not with  0, as it is a part of string 
                can_change.push(i);
            } else if (s[i] == '(') {
                open_Brackets.push(i);
            } else if (s[i] == ')') {
                if (!open_Brackets.empty()) {
                    open_Brackets.pop();
                } else if (!can_change.empty()) {
                    can_change.pop();
                } else {
                    return false;
                }
            }
        }
            while(!open_Brackets.empty() && !can_change.empty() && open_Brackets.top() < can_change.top()){
                open_Brackets.pop();
                can_change.pop();
            }
            if(!open_Brackets.empty()) return false;
        return true;
    }
};
