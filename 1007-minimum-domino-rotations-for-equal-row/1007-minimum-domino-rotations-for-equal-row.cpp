class Solution {//TC:O(2.N)  SC:O(1)
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int>target = {tops[0],bottoms[0]};
        for(int num: target) {
            int missA = 0, missB = 0; // indicates the missing values in both top and bottom vectors
            bool valid = true;
            for(int i = 0;i<n;i++) {
                if(tops[i] != num and bottoms[i] != num) {
                    valid = false;
                    break;
                }
                if(tops[i] != num) missA++;
                if(bottoms[i] != num) missB++;
            }
            if(valid) return min(missA,missB);
        }
        return -1;
    }
};
//we can traverse for all numbers 0 - 6 but we can take these beginning elements in both the vectors 
// instead of TC:(6.N) we can solve this in O(2.N)
