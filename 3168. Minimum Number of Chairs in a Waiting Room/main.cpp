class Solution {//tc:o(n)  sc:o(1)
public:
    int minimumChairs(string s) {
        int ans = 0 , count = 0;
        for(int i = 0;i<s.length();i++) {
            if(s[i]=='E') {
                count++;
            }else {
                count--;
            }
            ans = max(ans,count);
        }
        return ans;// the MAX chairs at a point
    }
};
