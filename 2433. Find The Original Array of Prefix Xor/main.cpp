class Solution {//TIME O(n), SPACE O(1)
public:
    vector<int> findArray(vector<int>& pref) {
        int x = pref[0] , y ;
        for(int i = 1;i<pref.size();i++) {
            y = pref[i];
            pref[i] = (pref[i]^x);
            x = y;
        }
        return pref;
    }
};
