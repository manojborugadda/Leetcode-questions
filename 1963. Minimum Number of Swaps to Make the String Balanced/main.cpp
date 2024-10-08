class Solution {//TC:O(N)  SC:O(N)
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto ch: s) {
            if(ch == ']' and st.empty()) {
                continue;
            }else if(!st.empty() and ch == ']' and st.top() == '[') {// which means we got closed bracket and we will check if the top element is '['. if yes we have the balanced paranthesis now and remove that
                st.pop();
            }else {
                st.push('[');
            }
        }
        int unbalancedPairs = (st.size() +1) /2; //min no of swaps
        return unbalancedPairs;
    }
};
