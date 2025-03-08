class Solution {//TC:O(N)  SC:O(N) USING PREFIX SUM
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        vector<int>prefix(n+1,0);
        for(int i = 0;i<n;i++) {
            if(blocks[i] == 'W') {
                prefix[i+1] = prefix[i]+1;
            }else {
                prefix[i+1] = prefix[i];
            }
        }

        int ans = INT_MAX;
        for(int i = k;i<=n;i++) {
            ans = min(ans,prefix[i]-prefix[i-k]);
        }
        return ans;
    }
};
