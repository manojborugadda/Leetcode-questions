class Solution {//tc:o(n)  sc:o(n)
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        int n = asteroids.size();
        stack<int>st;
        for(int i = 0;i<n;i++) {
            if(asteroids[i] > 0  or st.empty()) {//if the stack is empty or INCOMING element is POSITIVE
                st.push(asteroids[i]);
            }else {//if the current element is NEGATIVE
                while(!st.empty() and st.top() > 0 and st.top() < abs(asteroids[i]) ) {
                    st.pop();
                }
                if(!st.empty() and st.top() == abs(asteroids[i])) {
                    st.pop();
                }else if(st.empty() or st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }
        ans.resize(st.size());
        int m = st.size();
        for(int i = m-1;i>=0;i--) {//if we push the elements from stack to ans vector we will get answer in reverse order so we insert elements from ENDING
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
