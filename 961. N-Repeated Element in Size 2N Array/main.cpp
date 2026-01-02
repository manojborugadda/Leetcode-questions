class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_set<int>st;
        for(auto num : nums) {
            if(st.find(num) != st.end()) {
                return num;
            }
            st.insert(num);
        }
        return 0;
    }
};
