class Solution { 
public:
    int calculate(string s) {
        int res = 0 , sign = 1;
        stack<int>st;
        for(int i = 0;i<s.size();i++) {
            char ch = s[i];
            if(ch >= '0' and ch <= '9') {
                int num = 0;
                while(i < s.length() and s[i] >= '0' and s[i] <= '9')  {
                    num = num*10 + (s[i++] - '0');
                }
                res += sign*num;
                i--;
            } else if(ch == '+') sign = 1;
              else if(ch == '-') sign = -1;
              else if( ch == '(' ) {
                  st.push(res);
                  st.push(sign);
                  res = 0;
                  sign = 1;
              } else if( ch == ')' ) {
                  res  = res * st.top();
                  st.pop();
                  res += st.top();
                  st.pop();
              }
        }
        return res;
    }
};
