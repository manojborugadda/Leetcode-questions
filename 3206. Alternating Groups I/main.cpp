class Solution {//TC:O(N+K-1)  SC:O(1)
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int left = 0;
        int ans = 0;
        int k = 3; // condition for 3 Contiguous tiles with alternate colours
        for(int right = 1;right < (n+k-1);right++) {
            if(colors[right % n] == colors[(right-1)% n]) {
                left = right; //skip the subarray condition
            }
            if(right - left + 1 == k) { // if we get the alternative group with K size
                ans++;
                left++;
            }
        }
        return ans;
    }
};

// same as leetcode 3208. Alternating Groups II  quesion but here K = 3
