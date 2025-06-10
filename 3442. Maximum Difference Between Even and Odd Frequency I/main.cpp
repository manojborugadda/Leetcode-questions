class Solution {//TC:O(N)  SC:O(N)
public:
    int maxDifference(string s) {
        unordered_map<char,int>map;
        for(char ch : s) {
            map[ch]++;
        }
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        vector<int>freq;
        for(auto [a,b] : map) {
            if(b % 2 == 0) {
                if( b < minEven) {
                    minEven = b;
                }
            }else {
                if( b > maxOdd) {
                    maxOdd = b;
                }
            }
        }
        if( minEven == INT_MAX or maxOdd == INT_MIN) {
            return 0;
        }
        return maxOdd - minEven;
    }
};
