class Solution {//TC:O(N) SC:O(N)
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>left(n),right(n);

        // Build the left array (count of '0's from the left)
        left[0] = (s[0] == '0') ? 1 : 0;
        for(int i = 1;i<n;i++) {
                left[i] = left[i-1]+(s[i] == '0' ? 1 : 0);
        }

        // Building the right array (count of '1's from the right)
        right[n - 1] = (s[n - 1] == '1') ? 1 : 0;
        for(int i = n-2 ;i>=0;i--) {
                right[i] = right[i+1]+(s[i] == '1' ? 1 :0);
        }

        int ans = INT_MIN;
        for(int i =0;i<n-1;i++) {
            ans = max(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};
