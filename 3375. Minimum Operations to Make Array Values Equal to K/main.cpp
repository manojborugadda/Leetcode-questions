class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        set<int>st;
        for(int num : nums) {
            if(num < k) return -1;
            else if( num != k) {
                st.insert(num);
            }
        }
        return st.size();
    }
};
//return the number of distinct integers in the array that are greater than k.
