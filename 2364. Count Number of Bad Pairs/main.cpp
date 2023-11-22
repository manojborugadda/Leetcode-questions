class Solution {//TC:O(N)  SC:O(N)
public:
    long long countBadPairs(vector<int>& nums) {
         //total pairs = good pairs + bad pairs
         // bad pairs = total pairs - good pairs

         unordered_map<int,int>map;
         int n = nums.size();
         long long goodPairsCount = 0;
         for(int i = 0;i<n;i++) {
            int diff = nums[i]-i;
            goodPairsCount += map[diff];
            map[diff]++;
         }

         long long totalPairs = ((long long)(n-1)*(long long)(n))/2;
         return totalPairs - goodPairsCount;
    }
};
