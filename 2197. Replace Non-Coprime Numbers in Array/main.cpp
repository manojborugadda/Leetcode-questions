class Solution {//tc:o(n)  sc:o(n)
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        stack<int>st;
        int n = nums.size();
        for(int i = 0;i<n;i++) {
            st.push(nums[i]);
            while (st.size() >= 2) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            long long g = __gcd(a, b);
            if (g > 1) {
                long long lcm = (1LL * a * b) / g;
                st.push((int)lcm);
            } else {
                st.push(b);
                st.push(a);
                break;
            }
        }
    }
        //inserting elements from STACK to arrays
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};

/**

Just remember this.

gcd(a,b) x lcm(a,b) = a x b

From this you can get:

lcm(a, b) = (a x b) / gcd(a, b)

*/
