class Solution {//tc:o(n)  sc;o(n)
public:
    bool solve(stack<char>& st) {
        if (st.size() < 2) return false;  // Ensure there are at least two elements

        char a = st.top(); 
        st.pop();
        char b = st.top();
        st.pop();
        
        // Check if the pair forms "AB" or "CD"
        if ((a == 'B' && b == 'A') || (a == 'D' && b == 'C')) {
            return true;
        }

        // If not, push them back in the stack
        st.push(b);
        st.push(a);
        return false;
    }

    int minLength(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            st.push(s[i]);
            // Continuously check the stack and remove pairs if found
            while (st.size() >= 2 && solve(st)) {
                // Pairs are already removed in the solve function
            }
        }
        return st.size();  // Return the remaining size of the stack
    }
};
