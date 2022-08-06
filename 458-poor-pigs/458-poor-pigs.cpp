class Solution {//TC:O(LOG(1000)) ~ O(1)  SC:O(1)
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = ( minutesToTest / minutesToDie ) + 1;
        return ceil( log(buckets)/log(states) );
    }
};