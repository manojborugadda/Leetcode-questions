class Solution {//TC:O(nlogn) , SC:O(1)
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles),end(piles));
        int n = piles.size();
        int i = 0, j = n-1;
        int ans = 0;
        while(i < j) {
            ans += piles[j-1];
            i++;
            j -= 2;
        }
        return ans;
    }
};
