class Solution {
public:
    int numTrees(int n) {
        if(n == 0 or n == 1) return 1;
        int ans = 0;
        for(int i = 1;i<=n;i++) {
            int sum = numTrees(i-1) * numTrees(n-i);
            ans += sum;
        }
        return ans;
    }
};
